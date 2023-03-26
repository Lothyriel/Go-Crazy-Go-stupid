#include <stdio.h>
#include <stdlib.h>

float getPoupado(int parcelas, float valor, float cdi, float valorParcelado, float valorParcela);

int main()
{    
    float valor;
    printf("Insira o valor do pagamento a vista\n");
    scanf("%f",&valor);

    float valorParcelado;
    printf("Insira o valor do pagamento parcelado\n");
    scanf("%f",&valorParcelado);
    
    float desconto = valorParcelado - valor;
    if(desconto < 0)
    {
        printf("A vista é mais caro????");
        return 0;
    }

    int parcelas;
    printf("Insira a quantidade de parcelas\n");
    scanf("%d",&parcelas);

    float cdi;
    printf("Insira a taxa CDI em %%\n");
    scanf("%f",&cdi);

    float valorParcela = valorParcelado / parcelas;

    float poupado = getPoupado(parcelas, valor, cdi, valorParcelado, valorParcela);

    printf("Valor poupado se você parcelar: %.2f", poupado - desconto);

    return 0;
}

float getPoupado(int parcelas, float valor, float cdi, float valorParcelado, float valorParcela) 
{
    float restante = valorParcelado;
    float poupadoAcumulado = 0;
    for(int i = 0; i < parcelas; i++)
    {
        poupadoAcumulado += restante * (cdi / 12 / 100);
        restante -= valorParcela;
    }

    return poupadoAcumulado;
}
