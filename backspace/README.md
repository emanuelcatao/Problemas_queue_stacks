# Está balanceado

É muito comum na programação que façamos uso de símbolos que necessariamente pedem um par para que seu uso seja válido. Para essa questão trabalharemos um com um conjunto reduzido deles, que serão:
    
    (, ), [, ], {, }

Está balanceado se um caractere de abertura/fechamento tem um correspondente de abertura/fechamento. Exemplo: 
    
    ()[]

Está desbalanceado se um caractere de abertura/fechamento não tem um correspondente de abertura/fechamento. Exemplo 

    [(]


A tarefa é elaborar um programa em linguagem C, usando pilhas, para receber como entrada uma sequência de caracteres e retornar um true, caso esteja balanceado e false, caso esteja desbalanceado.
