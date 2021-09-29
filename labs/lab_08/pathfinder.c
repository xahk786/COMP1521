#include <sys/types.h>

#include <sys/stat.h>

#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>


static char **tokenize (char *string, char *separator);
static void free_tokens (char **tokens);
static bool is_executable (char *pathname);


int
main (int argc, char *argv[])
{
	//the which command in terminal, finds a path for an exe file 
	//for this lab, we need to create the which command 
	//tokenize function: input the string and separator, returns an array of strings that have been separated 
	//getenv function: input environment variable, returns directory for the variable
	//is_executable: input path to executable, returns bool 1 or 0 if executable or not 
	
	//traverse through all the directories in the path directory. 
	//for each iteration check if is_executable(argv[]) (use separator to get target exe.file)
	//if is_executable returns true, get the directory we are currently in and print to terminal.
	
	char second[strlen(argv[1])+2]; //size = len(argv) + 2*(null_term)
	strcpy(second,"/");

	strcat(second,argv[1]);
	
	char *temp_path = getenv("PATH");
	char path[strlen(temp_path) + 1];
	strcpy(path,temp_path);

	char **array = tokenize(path, ":");
	
	int i = 0;
	int found = 0;
	while (array[i] != NULL){
		char first[strlen(array[i])+strlen(second)+2]; //size = len(array[i]) + len(second) + 2(null_term)
		strcpy(first,array[i]);
		strcat(first,second);
		if(is_executable(first)){
			printf("%s\n", first);
			found++;			
		}
		i++;
	}

	free_tokens (array);
	if (found){
		return 0;
	} else {
		printf("%s not found\n", argv[1]);
		return 0;
	}


	


}


////////////////////////////////////////////////////////////////////////
//    . . . you do not need to modify code beyond this point . . .    //

//
// Split a string 'str' into pieces by any one of a set of separators.
// Returns an array of strings, with the last element being `NULL'.
// The array itself, and the strings, are allocated with `malloc(3)';
// the provided `free_token' function can deallocate this.
//
static char **
tokenize (char *str, char *sep)
{
	size_t n_tokens = 0;
	char **tokens = NULL;

	while (*str != '\0') {
		// We are pointing at zero or more of any of the separators.
		// Skip all leading instances of the separators.
		str += strspn (str, sep);

		// Trailing separators after the last token mean that, at this
		// point, we are looking at the end of the string, so:
		if (*str == '\0')
			break;

		// Now, `s' points at one or more characters we want to keep.
		// The number of non-separator characters is the token length.
		// Allocate a copy of the token, and preserve it.
		size_t len = strcspn (str, sep);
		char *tok = strndup (str, len);
		assert (tok != NULL);
		str += len;

		// Add this token.  (Should really use reallocarray(3) here.)
		tokens = realloc (tokens, ++n_tokens * sizeof *tokens);
		tokens[n_tokens - 1] = tok;
	}

	// Add the final `NULL'.
	tokens = realloc (tokens, ++n_tokens * sizeof *tokens);
	tokens[n_tokens - 1] = NULL;

	return tokens;
}

//
// Free an array of strings.
//
static void
free_tokens (char **tokens)
{
	for (int i = 0; tokens != NULL && tokens[i] != NULL; i++)
		free (tokens[i]);

	free (tokens);
}


//
// Check whether this process can execute a file.
//
static bool
is_executable (char *pathname)
{
	struct stat s;
	return
		// does the file exist?
		stat (pathname, &s) == 0 &&
		// is the file a regular file?
		S_ISREG (s.st_mode) &&
		// can we execute it?
		faccessat (AT_FDCWD, pathname, X_OK, AT_EACCESS) == 0;
}
