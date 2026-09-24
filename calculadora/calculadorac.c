#include <stdio.h>

int main()
{

    int num1;
    int num2;
    int op = 0;

    printf("ingresar el primer numero: ");
    scanf("%d", &num1);
    printf("ingresar el segundo numero: ");
    scanf("%d", &num2);

    do
    {

        printf("en este menu  elija la operacion que realizara\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicacion\n");
        printf("4. Division\n");
        printf("5. Salir\n");
        printf("Ingrese la opcion: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            int suma = num1 + num2;
            printf("la suma es %d\n", suma);
            break;
        }

        case 2:
        {
            int resta = num1 - num2;
            printf("la resta es %d\n", resta);
            break;
        }

        case 3:
        {
            int multiplicacion = num1 * num2;
            printf("la multiplicacion es %d\n", multiplicacion);
            break;
        }

        case 4:
        {
            if (num2 == 0)
            {
                printf("no se puede dividir entre cero\n");
                break;
            }

            double division = (double)num1 / num2;
            printf("la division es %f\n", division);
            break;
        }

        case 5:
            printf("saliendo del programa\n");
            break;

        default:
            printf("opcion no encontrada\n");
            break;
        }

    } while (op != 5);

    return 0;
}
