# Lab 1 - part 2

##

```cpp
void** getRepDataPtr(shint* d_size)
{
	shint i;
	for (i = 0; i < L_REP_MAX; i++)
	{
		if (report_act[i] == 0)
			break;
	}
	if (i == L_REP_MAX)
	{
		*d_size = NULL;
		return NULL;
	}
	*d_size = AG_SIZE;
	report_act[i] = 1;
	return RepDataPtr[i];
}
```
