# Logger for C++

Example of the very simple logger used in the C project.
Prepare new version in C++

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


