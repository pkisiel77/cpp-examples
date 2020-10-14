# Logger for C++

Below is an example of a very very simple C logger  used in a C project. 

Prepare a new version in C ++ (file, memory, db provider)

```c
int ZapiszDoLog(char *sciezka, char *tryb)
{
	FILE *fp = fopen(sciezka, "a");
	if (fp == NULL)
	{
		printf("Error opening LOG.DAT", "I/O Error");
		return -1;
	}
	// zapis data i time otwarcia systemu 
	shint godz, min, sek, dzien, miesiac, rok;
	czas_zegarowy(&godz, &min, &sek);
	data_systemowa(&dzien, &miesiac, &rok);
	fprintf(fp, "\n#LOG:[%.2d.%.2d.%.2d](czas) [%.2d.%.2d.%.4d](data)#%s", godz, min, sek, dzien, miesiac, rok, tryb);
	fclose(fp);

	return 0;
}
```


