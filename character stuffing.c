#include <stdio.h>
#include <string.h>

int main() {
	char h[10];
	char t[10];
	char ch[100];
	char add[10];
	char out[100];
	char esc[] = "esc";
	int k = 0;
	printf("Enter the characters :");
	scanf("%s", ch);
	printf("Enter a charcter that represents starting delimiter:");
	scanf("%s", h);
	printf("Enter a character that represents ending delimiter:");
	scanf("%s", t);
	printf("Enter a character that is to be stuffed:");
	scanf("%s", add);

	for (int i = 0; i <strlen(h); i++) {
		out[k] = h[i];
		k++;
	}

	for (int i = 0; i < strlen(ch); i++) {
		int count = 0;
		for (int j = i, l = 0; j < (i + strlen(h)); j++,l++) {
			if (ch[j] == h[l]) {
				count++;
			} else {
				break;
			}
		}
		if (count == strlen(h)) {
			for (int m = 0; m < strlen(add); m++) {
				out[k] = add[m];
				k++;
			}
		}
		count = 0;
		for (int j = i, l = 0; j < (i + strlen(t)); j++,l++) {
                        if (ch[j] == t[l]) {
                                count++;
                        } else {
                                break;
                        }
                }
                if (count == strlen(t)) {
                        for (int m = 0; m < strlen(add); m++) {
                                out[k] = add[m];
                                k++;
                        }
                }
		count = 0;
		for (int j = i, l = 0; j < (i + strlen(esc)); j++,l++) {
                        if (ch[j] == esc[l]) {
                                count++;
                        } else {
                                break;
                        }
                }
                if (count == strlen(esc)) {
                        for (int m = 0; m < strlen(add); m++) {
                                out[k] = add[m];
                                k++;
                        }
                }
		 
		out[k] = ch[i];
		k++;
	}

	for (int i = 0; i <strlen(t); i++) {
                out[k] = t[i];
                k++;
        }
	
	out[k] = '\0';

	printf("\nAfter Stuffing: %s\n", out);
	return 0;
}