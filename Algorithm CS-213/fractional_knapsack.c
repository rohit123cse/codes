#include <stdio.h>
void sort(float a[], float itm[], float val[], int n)
{
  int k;
  do
  {
    k = 0;
    for (int i = 0; i < n - 1; i++)
    {
      if (a[i] < a[i + 1])
      {
        float h = a[i];
        a[i] = a[i + 1];
        a[i + 1] = h;

        float x = itm[i];
        itm[i] = itm[i + 1];
        itm[i + 1] = x;

        float y = val[i];
        val[i] = val[i + 1];
        val[i + 1] = y;
        k++;
      }
    }
  } while (k > 0);
}
int main()
{
  int n, cap;
  scanf("%i %i", &n, &cap);
  float itm[n], val[n], uni[n];
  float r[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%f %f %f", &itm[i], &val[i], &uni[i]);
    itm[i] *= uni[i];
    val[i] *= uni[i];
    r[i] = val[i] / itm[i];
  }

  sort(r, itm, val, n);

  double sum = 0;
  double out = 0;

  for (int i = 0; i < n; i++)
  {
    if (sum + itm[i] <= cap)
    {
      sum += itm[i];
      out += val[i];
    }
    else
    {
      out += ((cap - sum) / itm[i]) * val[i];
      break;
    }
  }
  printf("%lf", out);
}