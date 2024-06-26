//KMP

#include<stdio.h>
#include<string.h>

void computeLPSArray(char* pat, int m, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i<m){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int cnt = 0;
	int lps[M];
	computeLPSArray(pat, M, lps);
	int i = 0;
	int j = 0;
	
	while(i<N)
	{
		if(pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if(j==M)
		{
			printf("Pattern found at index: %d\n", i-j);
			cnt++;
			j = lps[j-1];
		}
		else if(i<N && pat[j] != txt[i])
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}
int main()
{
	char txt[] = "AABAACAADAABAABA";
	char pat[] = "AABA";
	KMPSearch(pat,txt);
	return 0;
}
