
// Assume s1 and s ARE Null-terminated
// or just assume there is a null character in both s1 and s
char *safestrcpy(char *s1, const char *s) {
	while(!(*s1 == '\0' && *s == '\0')) {
		*s1=*s;
		s1++;
		s++;
	}
	return s1;

	while((*s1=*s)!='\0');
}

