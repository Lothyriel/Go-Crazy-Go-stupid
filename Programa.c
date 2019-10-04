#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cdi,valor,valorparcela,poupado=0;
    int parcelas;

    printf("Insira o valor do pagamento\n");
    scanf("%f",&valor);
    printf("Insira a quantidade de parcelas\n");
    scanf("%d",&parcelas);
    printf("Insira a taxa CDI em %%\n");
    scanf("%f",&cdi);

    valorparcela=valor/parcelas;

    for(int i=0;i<parcelas;i++)
    {
        poupado=poupado+valor*(cdi/12/100);
        valor=valor-valorparcela;
    }
    printf("Valor Poupado: %.2f",poupado);

    return 0;
}
