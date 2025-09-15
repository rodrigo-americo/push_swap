#include <stdio.h>
#include "push_swap.h"

int main(void)
{
    t_intvec vec;
    int i;

    if (!ft_intvec_init(&vec, 1))
    {
        printf("Erro ao inicializar vetor\n");
        return (1);
    }

    printf("Init: len=%zu cap=%zu\n", vec.len, vec.cap);

    // Inserir 10 valores para forçar vários resizes
    for (i = 0; i < 10; i++)
    {
        if (!ft_intvec_push(&vec, i * 10))
        {
            printf("Erro no push %d\n", i);
            ft_intvec_free(&vec);
            return (1);
        }
        printf("Push %d: len=%zu cap=%zu último=%d\n",
               i, vec.len, vec.cap, vec.data[vec.len - 1]);
    }

    // Mostrar conteúdo completo
    printf("\nConteúdo final:\n");
    for (i = 0; i < (int)vec.len; i++)
        printf("[%d] = %d\n", i, vec.data[i]);

    ft_intvec_free(&vec);
    printf("\nDepois do free: len=%zu cap=%zu data=%p\n",
           vec.len, vec.cap, (void *)vec.data);

    return (0);
}
