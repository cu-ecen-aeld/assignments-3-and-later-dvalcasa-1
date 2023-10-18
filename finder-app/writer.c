#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

// Author: dvalcasa

int main(int argc, char *argv[]) { 
	openlog(NULL, 0, LOG_USER);
	
	if (argc < 2 ) {
		syslog(LOG_ERR, "Invalid number of arguments %d", argc);
		return 1;
	}

	char *writefile, *writestr;
	
	writefile = argv[1];
	writestr = argv[2];

	FILE *file = fopen(writefile, "w");

	if ( file == NULL ) {
		fprintf(stderr, "Value of errno attempting to create file %s: %d\n", writefile, errno);
		perror("perror returned");
		syslog(LOG_ERR, "Error creating file %s: %s\n", writefile, strerror(errno));
		
		return 1;
	} else {
		syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
		fwrite(writestr, sizeof(char), strlen(writestr), file);
	
		fclose(file);
	}
	
	closelog();
	return 0;
}

