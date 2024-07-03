#ifndef FUNCIONES_H
#define FUNCIONES_H


using namespace std;

void imprime_arreglo(int *arreglo, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arreglo[i] << std::endl;
}

void merge(int *arreglo, int bajo, int valor_medio, int alto)
{
    int tempora[alto + 1];
    int i = bajo;
    int j = valor_medio + 1;
    int k = 0;

    while (i <= valor_medio && j <= alto)
    {
        if (arreglo[i] <= arreglo[j])
            tempora[k++] = arreglo[i++];
        else
            tempora[k++] = arreglo[j++];
    }
    while (i <= valor_medio)
        tempora[k++] = arreglo[i++];
    while (j <= alto)
        tempora[k++] = arreglo[j++];
    k--;
    while (k >= 0)
    {
        arreglo[k + bajo] = tempora[k];
        k--;
    }
}

void mergeSort(int *arreglo, int bajo, int alto)
{
    int valor_medio;

    if (bajo < alto)
    {
        valor_medio = (bajo + alto) / 2;
        mergeSort(arreglo, bajo, valor_medio);
        mergeSort(arreglo, valor_medio + 1, alto);
        merge(arreglo, bajo, valor_medio, alto);
    }
}



void quickSort(int *arreglo, int bajo, int alto)
{
int i = bajo;
int j = alto;
int pivot = arreglo[(i + j) / 2];
int tempora;
while (i <= j)
    {
while (arreglo[i] < pivot)
            i++;
while (arreglo[j] > pivot)
            j--;
if (i <= j)
        {
            tempora = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = tempora;
            i++;
            j--;
        }
    }
if (j > bajo)
quickSort(arreglo, bajo, j);
if (i < alto)
quickSort(arreglo, i, alto);
}




void selectionSort(int *arreglo, int n)
{
int tempora;
int minimo;
for (int i = 0; i < n; ++i)
    {
        minimo = i;
for (int j = i + 1; j < n; ++j)
        {
if (arreglo[j] < arreglo[minimo])
                minimo = j;
        }
if (minimo != i)
        {
            tempora = arreglo[i];
            arreglo[i] = arreglo[minimo];
            arreglo[minimo] = tempora;
        }
    }
}



int binarySearch(int *arreglo, int n, int elemento)
{
int bajo = 0;
int alto = n - 1;
while (bajo <= alto)
    {
int medio = (bajo + alto) / 2;
if (arreglo[medio] == elemento)
return medio;
else if (arreglo[medio] < elemento)
            bajo = medio + 1;
else
            alto = medio - 1;
    }
return -1;
}

int binarySearchFirst(int *arreglo, int n, int elemento)
{
int bajo = 0;
int alto = n - 1;
int first = -1;
while (bajo <= alto)
    {
int medio = (bajo + alto) / 2;
if (arreglo[medio] == elemento)
        {
            first = medio;
            alto = medio - 1;
        }
else if (arreglo[medio] < elemento)
            bajo = medio + 1;
else
            alto = medio - 1;
    }
return first;
}

int binarySearchLast(int *arreglo, int n, int elemento)
{
int bajo = 0;
int alto = n - 1;
int last = -1;
while (bajo <= alto)
    {
int medio = (bajo + alto) / 2;
if (arreglo[medio] == elemento)
        {
            last = medio;
            bajo = medio + 1;
        }
else if (arreglo[medio] < elemento)
            bajo = medio + 1;
else
            alto = medio - 1;
    }
return last;
}



void FibonacciSearch(int *a, int start, int end, int *busque_arr, int index, int item)
{
	int i, mid;

	mid = start+busque_arr[index-2];

	if(item == a[mid])
	{
		cout<<"\nValor en "<<mid<<" indexado.";
		return;
	}
	else if(item == a[start])
	{
		cout<<"\nValor en "<<start<<" indexado.";
		return;
	}
	else if(item == a[end])
	{
		cout<<"\nValor en "<<end<<" indexado.";
		return;
	}
	else if(mid == start || mid == end)
	{
		cout<<"\nNo se encontro";
		return;
	}
	else if(item > a[mid])
		FibonacciSearch(a, mid, end, busque_arr, index-1, item);
	else
		FibonacciSearch(a, start, mid, busque_arr, index-2, item);
}








#endif
