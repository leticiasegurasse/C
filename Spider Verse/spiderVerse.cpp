#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>
#include <windows.h>

/*
- Colocar na loja op��o de ir da parte de cura para a parte de habilidade e vice versa
*/

//Fun��o aleat�rio
int aleatorio () {
    int min = 1, max = 6;
    
    srand(time(0));
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

//Fun��o b�nus vida
int bonusVida(int vidaHeroi){
    int num, bonus;
    char texto[9999];
    int tamanho = strlen(texto);
    
    if (vidaHeroi < 100){
        num = aleatorio();
        //num = 1;
        switch(num){
            case 1:
                strcpy(texto, "Homem Aranha: Ei, meu amigo her�i! Eu ouvi dizer que voc� tem enfrentado algumas batalhas dif�ceis recentemente. Como forma de retribuir toda a sua coragem e dedica��o, decidi enviar um kit de cura como presente para voc�.\n\n"); 
                tamanho = strlen(texto);
                for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
                }
                bonus = 1;
                break;
                
            default: 
                bonus = 0;
                break;
    }
    }else{
        bonus = 0;
    }
    
    return bonus;
}

//Op��es de Ataque
int ataques(int nivelHeroi){
    int opcao=0;
    
    printf("Escolha um golpe:\n");
    printf("1 - Soco Voador\n");
    printf("2 - Ataque a Dist�ncia\n");
    if (nivelHeroi == 1){
        printf("3 - Teia El�trica\n");
        
        do{
            scanf("%d", &opcao);  
            if((opcao < 1)||(opcao > 3)){
                printf("Op��o Inv�lida! Digite novamente...\n");
            }
        }while((opcao < 1)||(opcao > 3)); 
    
    }else if (nivelHeroi == 2){
        printf("3 - Teia El�trica\n");
        printf("4 - Lan�ar bombinhas\n");
        
        do{
            scanf("%d", &opcao);  
            if((opcao < 1)||(opcao > 4)){
                printf("Op��o Inv�lida! Digite novamente...\n");
            }
        }while((opcao < 1)||(opcao > 4)); 
   
     }else if (nivelHeroi == 0){
         do{
            scanf("%d", &opcao);  
            if((opcao < 1)||(opcao > 2)){
                printf("Op��o Inv�lida! Digite novamente...\n");
            }
         }while((opcao < 1)||(opcao > 2)); 
     }else{
         printf("Corrigir BUG");
     }
     
    return opcao;
}

//Chance de Acerto do Ataque
int resultado_ataque (){
    int numero = aleatorio();
    
    if ((numero == 1) or (numero == 2)) {
        printf("Voce errou o ataque!\n");
    } else if ((numero == 3) ||(numero == 4) or (numero == 5)) {
        printf("Voce acertou o ataque!\n");
    } else if (numero == 6) {
        printf("Voce acertou um ataque critico!\n");
    } else {
        printf("Bug! Numero errado recebido no resultado_acao\n");
    }
    
    return numero;
} 

//Chance de Acerto do Ataque Vil�o
int resultado_ataqueVilao (){
    int numero = aleatorio();
    
    if ((numero == 1) || (numero == 2) || (numero == 3)) {
        printf("\nUAU! Voc� desviou do ataque\n");
    } else if ((numero == 4) or (numero == 5) || (numero == 6) || (numero == 7) || (numero == 8)) {
        printf("O vil�o acertou o ataque!\n");
    } else if (numero == 9) {
        printf("\nEssa n�o! O vil�o acertou um ataque cr�tico, voc� est� imobilizado e perdeu uma rodada!\n\n");
    } else {
        printf("Bug! Numero errado recebido no resultado_acao\n");
    }
    
    return numero;
} 

//Miss�o de Sequestro ------------------------------------------------------------------------------------
int* sequestro(int forcaHeroi, int defesaHeroi, int vidaHeroi, int esquivaHeroi, int nivelHeroi){  
    int opcao, ataqueHeroi, velocidadeInimigo=10, forcaInimigo=15, defesaInimigo=5, vidaInimigo=100, possivelDesvio, chanceSalvamento, vitoria=0, tamanho=2;
    int* vetor=(int*)malloc(tamanho * sizeof(int));
    
    printf("Voc� chegou ao local do crime, qual sua primeira a��o ?\n \n");
    printf("1 - Enfrentar os inimigos\n");
    printf("2 - Salvar os ref�ns de modo silencioso\n");
    
    do{
        scanf("%d", &opcao);  
        if((opcao < 1)||(opcao > 2)){
            printf("Op��o Inv�lida! Digite novamente...\n");
        }
    }while((opcao < 1)||(opcao > 2));
    system("cls");
    switch(opcao){
        case 1: //Op��o 1 - Enfrentar Inimigo
        
                do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                   
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                    
                    if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");
                vitoria = 1; //Reputa��o (+5) | Moedas (+100)
        break;
        
        case 2: //Op��o 2 - Salvar os ref�ns de modo silencioso
            chanceSalvamento = aleatorio();
                
            if(chanceSalvamento >= 5){
                printf("PARAB�NS! Voc� conseguiu salvar os ref�ns sem causar alarde. O sequestrador foi abatido pela pol�cia e voc� salvou o dia.\n");
                printf("\nSua recompensa: +5 Reputa��o | +50 Moedas\n");
                vitoria = 2; //Reputa��o (+5) | Moedas (+50)
            }else{
            
                 printf("A invas�o silenciosa n�o deu certo, os inimigos te encontraram! \nEsteja prepado para a batalha...\n\n");       
                 
                 system("Pause");
                 system("cls");
                 
                 do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                   if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));              
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");        
                vitoria = 3; //Reputa��o (+5) | Moedas (+100)
            }
        break;
    }
    vetor[1] = vitoria;
    vetor[2] = vidaHeroi;
    
    return vetor;
}

//Miss�o de Gangue ------------------------------------------------------------------------------------
int* gangue(int forcaHeroi, int defesaHeroi, int vidaHeroi, int esquivaHeroi, int nivelHeroi){  
    int opcao, ataqueHeroi, velocidadeInimigo=10, forcaInimigo=15, defesaInimigo=5, vidaInimigo=100, possivelDesvio, chanceSalvamento, vitoria=0, tamanho=2;
    int* vetor=(int*)malloc(tamanho * sizeof(int));
    
    printf("Voc� chegou ao local do crime, qual sua primeira a��o ?\n \n");
    printf("1 - Enfrentar os inimigos\n");
    printf("2 - Emboscada na Rua Escura\n");
    
    do{
        scanf("%d", &opcao);  
        if((opcao < 1)||(opcao > 2)){
            printf("Op��o Inv�lida! Digite novamente...\n");
        }
    }while((opcao < 1)||(opcao > 2));
    system("cls");
    switch(opcao){
        case 1: //Op��o 1 - Enfrentar Inimigo
                
                do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                   
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                    
                    if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");
                vitoria = 1; //Reputa��o (+5) | Moedas (+100)
        break;
        
        case 2: //Op��o 2 - Emboscada na Rua Escura
            chanceSalvamento = aleatorio();
                
            if(chanceSalvamento >= 5){
                printf("PARAB�NS! Voc� conseguiu envolver a gangue em sua pr�pria teia, deixando-os completamente surpresos e incapazes de revidar o ataque.\n");
                printf("\nSua recompensa: +5 Reputa��o | 50 Moedas\n");
                vitoria = 2; //Reputa��o (+5) | Moedas (+50)
            }else{
            
                 printf("A emboscada na rua escura n�o deu certo, os inimigos te avistaram! \nEsteja prepado para a batalha...\n\n");       
                 
                 system("Pause");
                 system("cls");
                 
                 do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                   if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));              
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");        
                vitoria = 3; //Reputa��o (+5) | Moedas (+100)
            }
        break;
    }
    vetor[1] = vitoria;
    vetor[2] = vidaHeroi;
    
    return vetor;
}

//Miss�o Invas�o Rob� ------------------------------------------------------------------------------------
int* invasao(int forcaHeroi, int defesaHeroi, int vidaHeroi, int esquivaHeroi, int nivelHeroi){  
    int opcao, ataqueHeroi, velocidadeInimigo=10, forcaInimigo=15, defesaInimigo=5, vidaInimigo=100, possivelDesvio, chanceSalvamento, vitoria=0, tamanho=2;
    int* vetor=(int*)malloc(tamanho * sizeof(int));
    
    printf("Voc� chegou ao local do crime, qual sua primeira a��o ?\n \n");
    printf("1 - Enfrentar os inimigos\n");
    printf("2 - Preparar armadilha\n");
    
    do{
        scanf("%d", &opcao);  
        if((opcao < 1)||(opcao > 2)){
            printf("Op��o Inv�lida! Digite novamente...\n");
        }
    }while((opcao < 1)||(opcao > 2));
    system("cls");
    switch(opcao){
        case 1: //Op��o 1 - Enfrentar Inimigo
                
                do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                   
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                    
                    if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");
                vitoria = 1; //Reputa��o (+5) | Moedas (+100)
        break;
        
        case 2: //Op��o 2 - Preparar armadilha
            chanceSalvamento = aleatorio();
                
            if(chanceSalvamento >= 5){
                printf("PARAB�NS! Voc� conseguiu prender os rob�s em sua armadilha e desativa-los.\n");
                printf("\nSua recompensa: +5 Reputa��o | +50 Moedas\n");
                vitoria = 2; //Reputa��o (+5) | Moedas (+50)
            }else{
            
                 printf("OH N�O! Os rob�s conseguiram escapar da armadilha. \nEsteja prepado para a batalha...\n\n");       
                 
                 system("Pause");
                 system("cls");
                 
                 do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                   if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));              
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");        
                vitoria = 3; //Reputa��o (+5) | Moedas (+100)
            }
        break;
    }
    vetor[1] = vitoria;
    vetor[2] = vidaHeroi;
    
    return vetor;
}

//Miss�o Batalha nas Alturas ------------------------------------------------------------------------------------
int* batalhaAltura(int forcaHeroi, int defesaHeroi, int vidaHeroi, int esquivaHeroi, int nivelHeroi){  
    int opcao, ataqueHeroi, velocidadeInimigo=10, forcaInimigo=15, defesaInimigo=5, vidaInimigo=100, possivelDesvio, chanceSalvamento, vitoria=0, tamanho=2;
    int* vetor=(int*)malloc(tamanho * sizeof(int));
    
    printf("Voc� chegou ao local do crime, qual sua primeira a��o ?\n \n");
    printf("1 - Enfrentar inimigo\n");
    printf("2 - Preparar armadilha\n");
    
    do{
        scanf("%d", &opcao);  
        if((opcao < 1)||(opcao > 2)){
            printf("Op��o Inv�lida! Digite novamente...\n");
        }
    }while((opcao < 1)||(opcao > 2));
    system("cls");
    switch(opcao){
        case 1: //Op��o 1 - Enfrentar Inimigo
                
                do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                   
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                    
                    if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");
                vitoria = 1; //Reputa��o (+5) | Moedas (+100)
        break;
        
        case 2: //Op��o 2 - Preparar armadilha
            chanceSalvamento = aleatorio();
                
            if(chanceSalvamento >= 5){
                printf("PARAB�NS! Voc� conseguiu prender os rob�s em sua armadilha e desativa-los.\n");
                printf("\nSua recompensa: +5 Reputa��o | +50 Moedas\n");
                vitoria = 2; //Reputa��o (+5) | Moedas (+50)
            }else{
            
                 printf("OH N�O! O vil�o conseguiu escapar da armadilha. \nEsteja prepado para a batalha...\n\n");       
                 
                 system("Pause");
                 system("cls");
                 
                 do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaInimigo = vidaInimigo - (forcaHeroi - defesaInimigo);
                    }else if(ataqueHeroi==6){
                    vidaInimigo = vidaInimigo - ((forcaHeroi - defesaInimigo)*2);
                    }
                    if (vidaInimigo <=0){
                        printf("Vida Inimigo: 0\n");
                    }else{
                        printf("Vida Inimigo: %d \n", vidaInimigo);
                    }
             
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }
                    
                    printf("\nAgora � a vez do seu oponente...\n \n");
                    system("Pause");
                                
                    possivelDesvio = aleatorio();
                    possivelDesvio = esquivaHeroi * possivelDesvio;
            
                    if (possivelDesvio >= 30){
                       printf("\nUAU! Voc� desviou do ataque\n");
                    }else{
                        printf("\nSeu inimigo acertou o ataque\n");
                        vidaHeroi = vidaHeroi - forcaInimigo;
                    }
                   if (vidaHeroi <=0){
                        printf("Sua vida: 0\n");
                    }else{
                        printf("Sua Vida: %d\n", vidaHeroi);
                    }
            
                    if (vidaInimigo <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        break; 
                    }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        return 0;
                    }
                    
                    system("Pause");
                    system("cls");
                }while((vidaInimigo > 0) && (vidaHeroi > 0));              
                printf("\nSua recompensa: +5 Reputa��o | +100 Moedas\n");        
                vitoria = 3; //Reputa��o (+5) | Moedas (+100)
            }
        break;
    }
    vetor[1] = vitoria;
    vetor[2] = vidaHeroi;
    
    return vetor;
}

//Salvar Gato ------------------------------------------------------------------------------------
int salvarGato(){  
    int opcao, chanceSalvamento, vitoria=0;
       
    chanceSalvamento = aleatorio();
                
    if(chanceSalvamento >= 4){
        printf("PARAB�NS! Voc� conseguiu salvar o gatinho.\n");
        printf("\nSua recompensa: +5 Reputa��o | +50 Moedas\n");
        vitoria = 2; //Reputa��o (+5) | Moedas (+50)
    }else{
        printf("OH N�O! Parece que o gatinho se assustou com sua presen�a e pulou da �rvore.\n\n");
        printf("O que voc� vai fazer?\n");
        printf("1 - Pegar o gato com a teia\n");
        printf("2 - Deixar cair\n");
    
        do{
            scanf("%d", &opcao);  
            if((opcao < 1)||(opcao > 2)){
                printf("Op��o Inv�lida! Digite novamente...\n");
            }
        }while((opcao < 1)||(opcao > 2));
        system("cls");
        switch(opcao){
            case 1:   
                printf("\nUFA! Dessa vez foi por pouco! O gatinho est� a salvo.");
                printf("\nSua recompensa: +5 Reputa��o | +50 Moedas\n");  
                vitoria = 2; //Reputa��o (+5) | Moedas (+50)
            break;
            
            case 2:
                printf("\nEssa n�o � a atitude que um her�i deveria ter!\n");
                printf("\nO gatinho n�o se machucou muito com a queda, mas os cidad�os est�o decepcionados!");
                printf("\nReputa��o -10\n");
                vitoria = 4; //Reputa��o (-10)
            break;
        }
    }
    
    return vitoria;
}

//ATAQUE BOSS -----------------------------------------------------------------------------------------------------------------
int* boss(int nivelHeroi, int forcaHeroi, int vidaHeroi, int defesaHeroi){

    int ataqueHeroi, ataqueVilao, vitoria=0, vidaVilao=100, forcaVilao=30, defesaVilao=8, tamanho=2;
    int* vetor=(int*)malloc(tamanho * sizeof(int));
    
    //Vil�o fica mais forte a cada n�vel
    if (nivelHeroi == 1) {
        forcaVilao = 34;
        defesaVilao = 10;
    }else if (nivelHeroi == 2){
        forcaVilao = 36;
        defesaVilao = 12;
    }
    
    
                do{
                    ataques(nivelHeroi);
                    ataqueHeroi = resultado_ataque();
                    
                    if ((ataqueHeroi==3) || (ataqueHeroi==4) || (ataqueHeroi==5)){
                        vidaVilao = vidaVilao - (forcaHeroi - defesaVilao);
                    }else if(ataqueHeroi==6){
                    vidaVilao = vidaVilao - ((forcaHeroi - defesaVilao) * 2);
                    }
                    
                    if (vidaVilao <=0){
                        printf("Vida Vil�o: 0\n");
                    }else{
                        printf("Vida Vil�o: %d \n", vidaVilao);
                    }
             
                    if (vidaVilao > 0){
                        printf("\nAgora � a vez do seu oponente...\n \n");
                        system("Pause");
                    
                        //ATAQUE BOSS
                        ataqueVilao = resultado_ataqueVilao();
                        
                        if ((ataqueVilao==4) || (ataqueVilao==5) || (ataqueVilao==6) || (ataqueVilao==7) || (ataqueVilao==8)){
                            vidaHeroi = vidaHeroi - (forcaVilao - defesaHeroi);
                        }else if(ataqueVilao==9){
                            vidaHeroi = vidaHeroi - ((forcaVilao - defesaHeroi) * 2);                   
                        }
                    
                        if (vidaHeroi <=0){
                            printf("Vida: 0\n");
                        }else{
                            printf("Vida: %d \n", vidaHeroi);
                            
                            if(ataqueVilao==9){
                                system("Pause");
                                system("cls");
                                printf("\n� a vez do seu oponente...\n \n");
                                Sleep(1000);
                                vidaHeroi = vidaHeroi - (forcaVilao - defesaHeroi); 
                                printf("O vil�o acertou o ataque!\n");
                            
                                if (vidaHeroi <=0){
                                    printf("\nOH N�O! Voc� perdeu!\n\n");
                                    printf("Vida: 0\n\n");
                                    system("Pause");
                                }else{
                                    printf("Vida: %d \n", vidaHeroi);
                                
                                }                       
                            }
                        
                        }
                    
                        system("Pause");
                        system("cls");
                        
                    }else {
                        vidaVilao=0;
                    }
                    
                }while((vidaVilao > 0) && (vidaHeroi > 0));
                
                
                
                if (vidaVilao <= 0){
                        printf("\nQUE INCR�VEL! Voc� derrotou o vil�o.\n");
                        printf("\nSua recompensa: +15 Reputa��o | +150 Moedas\n\n");
                        vitoria = 5; //+15 Reputa��o | +150 Moedas
                }else if (vidaHeroi <= 0){
                        printf("\nOH N�O! Voc� perdeu!\n\n");
                        system("Pause");
                        vitoria = 0;
                    }
    vetor[1] = vitoria;
    vetor[2] = vidaHeroi;
    
    return vetor;
}
        

//FUN��O PRINCIPAL -------------------------------------------------------------------------------------------
int main(){
setlocale(LC_ALL, "Portuguese"); 

    //Declara��o de Vari�veis
    char nomeHeroi[50];
    int habilidade, entrarSair, bonus =0, forca=30, defesa=10, esquiva=5, velocidade=20, reputacao=80, missao=0, proximaMissao, vida=100, nivel=0, moedas=0, vitoria=0, entrarLoja=0, itemLoja;
    int* meuVetor;
    
   // Mudar a cor da letra
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD corPadrao;
    // Obter informa��es da tela
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    corPadrao = consoleInfo.wAttributes;
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    
    //CR�DITOS
    printf("Trablho de Linguagem de Programa��o.\n\nAlunos:");
    printf("\n1- Leticia Segurasse - 1-23-14320");
    printf("\n2- Kallebe Assis - 1-22-12273");
    printf("\n3- Thiago Roncete - 1-23-14340");
    printf("\n4- Samuel Cardoso - 1-23-14333");
    printf("\n5- Felipe Cunha - 1-23-15514\n\n");
    
    system("Pause");
    system("cls");
    
    //Efeito digita��o
    char texto[9999];
    strcpy(texto, "Bem-vindos, her�is aracn�deos, � incr�vel cidade de Nova York! \nPreparem-se para entrar em um mundo repleto de a��o, desafios e emo��o, onde voc�s s�o os protagonistas da hist�ria.\n\nLembre-se: com grandes poderes v�m grandes responsabilidades. \nA cidade precisa de voc�s para se manter segura. Estejam preparados para tomar decis�es dif�ceis, sacrificar-se pelo bem maior e proteger os inocentes.\n \n"); //fun��o strcpy da biblioteca <string.h> para copiar a string para o array.
    int tamanho = strlen(texto);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20);  // Pausa de 100 milissegundos (ajuste o valor conforme desejado)
    }
    
    strcpy(texto, "Qual ser� o seu nome de her�i ?\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }     
    scanf("%s", &nomeHeroi);
    
    system("cls"); //Limpa Tela
    
    //Escolha de Habilidades
    strcpy(texto, "Escolha a habilidade que voc� deseja usar durante sua jornada:\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    } 
    Sleep(1000); 
    printf("\n1 - Aracno-acrobacia: Desenvolva habilidades acrob�ticas incr�veis, permitindo saltos mais altos, cambalhotas �geis e movimentos acrob�ticos impressionantes.\n");
    Sleep(1000);
    printf("\n2 - Teia de Prote��o: pode ser usada estrategicamente durante batalhas intensas, permitindo ao her�i resistir a ataques poderosos e proteger-se de danos significativos\n");
    Sleep(1000);
    printf("\n3 - For�a Aranha: Desenvolva uma for�a sobre-humana, capaz de levantar objetos pesados e enfrentar inimigos formid�veis\n");
    
    do{
        scanf("%d", &habilidade);  
        if((habilidade < 1)||(habilidade > 3)){
            printf("Habilidade Inexistente! Digite novamente...\n");
        }
    }while((habilidade < 1)||(habilidade > 3));
    
    switch(habilidade){
        case 1:
            esquiva = esquiva + 1; //mudei para 1 pq quando escolhia essa op��o e estava 20 ele desviava de todos os ataques
            break;
        
        case 2:
            defesa = defesa + 2;
            break;
            
        case 3:
            forca = forca + 3;
            break;
        
        default:
            printf("Corrigir BUG");
    }
    
    strcpy(texto, "Muito bem! Sua nova habilidade foi obtida com sucesso!\n \n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    } 
    system("Pause");
    system("cls"); //Limpa Tela
    
    strcpy(texto, "UAU! Sua reputa��o est� iniciando(80)! \nMas tome cuidado, se sua reputa��o for menor que 70 voc� ser� banido da cidade...\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    system("Pause");
    system("cls"); //Limpa Tela
    
//                    ---------------------------------------- PRIMEIRA FASE ----------------------------------------
    proximaMissao = aleatorio();
    //proximaMissao = 4; //TESTAR MISS�O SEPARADAS
    
    switch(proximaMissao){ //Defini��o aleat�ria da Pr�xima Miss�o do Jogo
        case 1: //Miss�o 01 - Sequestro
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Temos uma situa��o de emerg�ncia. Um grupo de criminosos perigosos mant�m ref�ns em um local espec�fico da cidade. As vidas dessas pessoas est�o em perigo, e precisamos da sua ajuda para resgat�-las.\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
            printf("\nDigite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = sequestro(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
            
            break;
        
        case 2: //Miss�o 02 - Gangues
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "A cidade est� sob a amea�a das gangues rivais que espalham o caos e a viol�ncia em suas disputas territoriais. � hora de agir! Como o defensor aracn�deo da justi�a, voc� � convocado para combater essas gangues e trazer a paz de volta �s ruas.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = gangue(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
        
        case 6:    
        case 3: //Miss�o 03 - Rob�s
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma grave amea�a se aproxima! Uma horda de rob�s controlados por um vil�o sinistro que est� planejando invadir uma �rea vital da cidade. A situa��o exige sua imediata interven��o para proteger os cidad�os e preservar a seguran�a da regi�o.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = invasao(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
            
        case 4: //Miss�o 04 - Batalha nas Alturas
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma misteriosa figura voadora est� aterrorizando a cidade, espalhando medo entre os cidad�os, detenha-o enquanto n�o cause danos maiores!\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = batalhaAltura(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
        
            break;
            
        case 5: //Miss�o 05 - Gato preso
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma situa��o de emerg�ncia requer sua aten��o imediata! Uma idosa est� precisando de sua ajuda com seu amado gato que est� preso no topo de uma �rvore alta, localizada na Rua Tranquilidade, pr�xima ao Parque Central.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Ajudar cidad�o\n");    
            printf("2 - Ignorar pedido\n");
            
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                vitoria = salvarGato();
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve ignorar o pedido de ajuda de um cidad�o.\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 4){ //Reputa��o (-10)
                reputacao = reputacao - 10;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            
            break;
    }
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
    vitoria = 0;
    
    system("Pause");
    system("cls");
    
    bonus = bonusVida(vida);
    //printf("Bonus: %d", bonus);
    
    if (bonus == 1){
        printf("\nVida Restaurada: 100%\n\n");
        vida = 100;
        
        system("Pause");
        system("cls");
    }else if (bonus == 0){
    
    }else{
        printf("Corrigir BUG");
    }
    
    
//                    ---------------------------------------- FIM PRIMEIRA FASE ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- SEGUNDA FASE ----------------------------------------
    proximaMissao = aleatorio();
    //proximaMissao = 4; //TESTAR MISS�O SEPARADAS
    
    switch(proximaMissao){ //Defini��o aleat�ria da Pr�xima Miss�o do Jogo
        case 1: //Miss�o 01 - Sequestro
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Temos uma situa��o de emerg�ncia. Um grupo de criminosos perigosos mant�m ref�ns em um local espec�fico da cidade. As vidas dessas pessoas est�o em perigo, e precisamos da sua ajuda para resgat�-las.\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
            printf("\nDigite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = sequestro(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
            
            break;
        
        case 2: //Miss�o 02 - Gangues
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "A cidade est� sob a amea�a das gangues rivais que espalham o caos e a viol�ncia em suas disputas territoriais. � hora de agir! Como o defensor aracn�deo da justi�a, voc� � convocado para combater essas gangues e trazer a paz de volta �s ruas.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = gangue(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
        
        case 6:    
        case 3: //Miss�o 03 - Rob�s
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma grave amea�a se aproxima! Uma horda de rob�s controlados por um vil�o sinistro que est� planejando invadir uma �rea vital da cidade. A situa��o exige sua imediata interven��o para proteger os cidad�os e preservar a seguran�a da regi�o.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = invasao(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
            
        case 4: //Miss�o 04 - Batalha nas Alturas
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma misteriosa figura voadora est� aterrorizando a cidade, espalhando medo entre os cidad�os, detenha-o enquanto n�o cause danos maiores!\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = batalhaAltura(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
        
            break;
            
        case 5: //Miss�o 05 - Gato preso
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma situa��o de emerg�ncia requer sua aten��o imediata! Uma idosa est� precisando de sua ajuda com seu amado gato que est� preso no topo de uma �rvore alta, localizada na Rua Tranquilidade, pr�xima ao Parque Central.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Ajudar cidad�o\n");    
            printf("2 - Ignorar pedido\n");
            
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                vitoria = salvarGato();
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve ignorar o pedido de ajuda de um cidad�o.\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 4){ //Reputa��o (-10)
                reputacao = reputacao - 10;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            
            break;
    }
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
    vitoria = 0;
    
    system("Pause");
    system("cls");
    
    bonus = bonusVida(vida);
    //printf("Bonus: %d", bonus);
    
    if (bonus == 1){
        printf("\nVida Restaurada: 100%\n\n");
        vida = 100;
        
        system("Pause");
        system("cls");
    }else if (bonus == 0){
    
    }else{
        printf("Corrigir BUG");
    }
    
//                    ---------------------------------------- FIM SEGUNDA FASE ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Loja
    if (moedas > 0){
        strcpy(texto, "Aproveite que a cidade est� livre de perigos para visitar a loja dos her�is!\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
        printf("1- Entrar na loja\n");
        printf("2- Sair da sala\n");
        
        do{
            scanf("%d", &entrarLoja);  
            if((entrarLoja < 1)||(entrarLoja > 2)){
            printf("Op��o Inv�lida! Digite novamente...\n");
            }
        }while((entrarLoja < 1)||(entrarLoja > 2));
        
        switch(entrarLoja){
            case 1:
            do{
                strcpy(texto, "O que voc� deseja ver agora?\n"); 
                tamanho = strlen(texto);
                for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
                }               
                printf("1- Kit cura\n");
                printf("2- Melhorar Habilidades\n");
                printf("3- Sair da loja\n\n");
                
                do{
                    scanf("%d", &entrarSair);  
                    if((entrarSair < 1)||(entrarSair >= 4)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                    }
                }while((entrarSair < 1)||(entrarSair > 4));
                itemLoja = entrarSair;
                if (itemLoja == 1){
                    system("cls");
                    printf("Suas moedas: %d\n", moedas);
                    printf("Sua vida: %d\n\n", vida);
                    printf("1- Cura (+20) = 40 moedas\n");
                    printf("2- Cura (+30) = 50 moedas\n");
                    printf("3- Cura Total = 100 moedas\n");
                    printf("4- Sair da loja\n");
                    do{
                        scanf("%d", &itemLoja);  
                        if((itemLoja < 1)||(itemLoja > 4)){
                        printf("Op��o Inv�lida! Digite novamente...\n");
                        }
                    }while((itemLoja < 1)||(itemLoja > 4));
                    
                    switch(itemLoja){
                        case 1:
                            if (vida <= 80){
                                if (moedas >= 40){
                                    vida = vida + 20;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 40;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if ((vida > 80) && (vida < 100)){
                                if (moedas >= 40){
                                    vida = 100;
                                    moedas = moedas - 40;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 40){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 2:
                            if (vida <= 70){
                                if (moedas >= 50){
                                    vida = vida + 30;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 50;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if ((vida > 70) && (vida < 100)){
                                if (moedas >= 50){
                                    vida = 100;
                                    moedas = moedas - 50;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 50){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 3:
                            if (vida < 100){
                                if (moedas >= 100){
                                    vida = 100;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 100;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 100){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                        
                        break;
                        
                        case 4:
                            printf("Obrigada por visitar nossa loja!\n\n");
                        break;
                        
                        default:
                            printf("Corrigir BUG");
                        
                    }
                    printf("Suas moedas: %d\n\n", moedas);
                    printf("Vida: %d\n\n", vida);
                    system("Pause");
                    system("cls");
                }else if (itemLoja == 2){
                    system("cls");
                    printf("Suas moedas: %d\n\n", moedas);
                    printf("1- Habilidade de For�a (+3) = 50 moedas\n");
                    printf("2- Habilidade de Defesa (+2) = 50 moedas\n");
                    printf("3- Habilidade de Esquiva (+1) = 100 moedas\n");
                    printf("4- Sair da loja\n");
                    do{
                        scanf("%d", &itemLoja);  
                        if((itemLoja < 1)||(itemLoja > 4)){
                        printf("Op��o Inv�lida! Digite novamente...\n");
                        }
                    }while((itemLoja < 1)||(itemLoja > 4));
                    
                    switch(itemLoja){
                        case 1:
                            if (moedas >= 50){
                                forca = forca + 3;
                                moedas = moedas - 50;
                                printf("\nFor�a (+3) total: %d\n\n", forca);
                            }else {
                                    printf("\nSaldo insuficiente.\n\n");
                            }
                            
                        break;
                        
                        case 2:
                            if (defesa >= 20){
                                printf("\nVoc� atingiu a defesa m�xima\n");
                                printf("\nDefesa: %d\n\n", defesa);
                            }else if (defesa < 20){
                                if (moedas >= 50){
                                    defesa = defesa + 2;
                                    moedas = moedas - 50;
                                    printf("\nDefesa (+2) total: %d\n\n", defesa);
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 3:
                            if (moedas >= 100){
                                esquiva = esquiva + 1;
                                moedas = moedas - 100;
                                printf("\nEsquiva (+1) total: %d\n\n", esquiva);
                            }else {
                                    printf("\nSaldo insuficiente.\n\n");
                            }
                            
                        break;
                        
                        case 4:
                            printf("Obrigada por visitar nossa loja!\n\n");
                        break;
                        
                        default:
                            printf("\nCorrigir BUG\n\n");
                        break;
                    }
                    printf("Suas moedas: %d\n\n", moedas);
                   
                    system("Pause");
                    system("cls");
                }
            
            }while(entrarSair != 3);  
            system("cls");  
            break;
            
            case 2:
                printf("Fique a vontade para visitar nossa loja quando quiser. At� mais!\n\n");
                
                system("Pause");
                system("cls");
            break;
        }
        
    }


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- VIL�O 1 ELECTRO ----------------------------------------

    printf("Chamado de emerg�ncia para %s! \n", nomeHeroi);
    Sleep(1000);
    strcpy(texto, "O terr�vel vil�o Electro declarou guerra � nossa cidade e est� causando uma onda de destrui��o por onde passa. Re�na suas teias, coloque seu uniforme e balance-se em dire��o � nossa cidade em perigo!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    printf("\nSpider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Ei, Electro! Voc� realmente acha que causar todo esse caos e destrui��o � a melhor maneira de resolver seus problemas?\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para amarelo
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    printf("\nElectro: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Ah, olha s� quem decidiu aparecer! Voc� sempre foi o queridinho da cidade, mas agora � a minha vez de brilhar. Com meus poderes el�tricos, posso mostrar a todos o meu verdadeiro poder!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("\nSpider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Voc� tem o poder de fazer a diferen�a de uma maneira positiva, Electro. Em vez de ser lembrado como um vil�o, por que n�o usa suas habilidades para ajudar os outros? Juntos, podemos encontrar uma solu��o para suas frustra��es.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para amarelo
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    printf("\nElectro: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Eu j� fiz minha escolha, e agora, � hora de voc� experimentar a ira el�trica de Electro!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    system("Pause");
    system("cls");
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    
    meuVetor = boss(nivel, forca, vida, defesa);
    vitoria = meuVetor[1];
    vida = meuVetor[2];
    
    //vitoria = 5 | +15 Reputa��o | +150 Moedas
    if (vitoria == 5){
        reputacao = reputacao + 15;
        moedas = moedas + 150;
        nivel++;
    }else if (vitoria == 0){
        // Alterar cor do texto para amarelo
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        strcpy(texto, "Electro: Suas teias e sua coragem n�o s�o p�reo para a for�a bruta da eletricidade! Voc� foi derrotado, reduzido a meros fragmentos diante do meu poder avassalador. A cidade agora conhecer� o reinado da eletricidade, e voc� ser� apenas uma lembran�a desbotada daqueles que tentaram me deter!\n\n"); 
        tamanho = strlen(texto);
        for (int i = 0; i < tamanho; i++) {
            printf("%c", texto[i]);
            Sleep(20); 
        }
        printf("\nFIM DE JOGO\n\n");
        system("Pause");
        return 0;
    }else {
        printf("Corrigir BUG");
    }
    
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("\nSpider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Electro, sua tempestade destrutiva foi dissipada! O poder da justi�a sempre prevalece sobre a escurid�o. Voc� foi derrotado!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
        
    // Alterar cor do texto para amarelo
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);    
    printf("Electro: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Voc� pode ter vencido desta vez, mas lembre-se bem: a eletricidade sempre encontra seu caminho de volta. Ainda nos veremos e a vingan�a ser� minha!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    
    
    system("Pause");
    system("cls");
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    strcpy(texto, "Parab�ns por derrotar o poderoso Electro! Sua determina��o e habilidades heroicas s�o dignas de admira��o.\n\nAl�m disso, sua vit�ria trouxe uma recompensa incr�vel voc� desbloqueou a nova habilidade da TEIA EL�TRICA! Agora, com essa poderosa arma adicional em seu arsenal, voc� est� pronto para enfrentar desafios ainda maiores e proteger a cidade com mais efic�cia do que nunca.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    bonus = bonusVida(vida);
    if (bonus == 1){
        printf("\nVida Restaurada: 100\n\n");
        vida = 100;
        system("Pause");
        system("cls");
    }else if (bonus == 0){
        printf("\nB�nus de Vida: 50\n\n");
        if (vida <= 50){
            vida = vida + 50;
        }else {
            vida = 100;
        }
    }else{
        printf("Corrigir BUG");
    }
    
    printf("Vida: %d\n\n", vida);
    system("Pause");
    system("cls");
    

//                    ---------------------------------------- FIM VIL�O 1 ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- TERCEIRA FASE ----------------------------------------
    proximaMissao = aleatorio();
    //proximaMissao = 4; //TESTAR MISS�O SEPARADAS
    
    switch(proximaMissao){ //Defini��o aleat�ria da Pr�xima Miss�o do Jogo
        case 1: //Miss�o 01 - Sequestro
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Temos uma situa��o de emerg�ncia. Um grupo de criminosos perigosos mant�m ref�ns em um local espec�fico da cidade. As vidas dessas pessoas est�o em perigo, e precisamos da sua ajuda para resgat�-las.\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
            printf("\nDigite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = sequestro(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
            
            break;
        
        case 2: //Miss�o 02 - Gangues
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "A cidade est� sob a amea�a das gangues rivais que espalham o caos e a viol�ncia em suas disputas territoriais. � hora de agir! Como o defensor aracn�deo da justi�a, voc� � convocado para combater essas gangues e trazer a paz de volta �s ruas.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = gangue(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
        
        case 6:    
        case 3: //Miss�o 03 - Rob�s
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma grave amea�a se aproxima! Uma horda de rob�s controlados por um vil�o sinistro que est� planejando invadir uma �rea vital da cidade. A situa��o exige sua imediata interven��o para proteger os cidad�os e preservar a seguran�a da regi�o.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = invasao(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
            
        case 4: //Miss�o 04 - Batalha nas Alturas
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma misteriosa figura voadora est� aterrorizando a cidade, espalhando medo entre os cidad�os, detenha-o enquanto n�o cause danos maiores!\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = batalhaAltura(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
        
            break;
            
        case 5: //Miss�o 05 - Gato preso
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma situa��o de emerg�ncia requer sua aten��o imediata! Uma idosa est� precisando de sua ajuda com seu amado gato que est� preso no topo de uma �rvore alta, localizada na Rua Tranquilidade, pr�xima ao Parque Central.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Ajudar cidad�o\n");    
            printf("2 - Ignorar pedido\n");
            
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                vitoria = salvarGato();
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve ignorar o pedido de ajuda de um cidad�o.\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 4){ //Reputa��o (-10)
                reputacao = reputacao - 10;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            
            break;
    }
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
    vitoria = 0;
    
    system("Pause");
    system("cls");
    
    bonus = bonusVida(vida);
    //printf("Bonus: %d", bonus);
    
    if (bonus == 1){
        printf("\nVida Restaurada: 100%\n\n");
        vida = 100;
        
        system("Pause");
        system("cls");
    }else if (bonus == 0){
    
    }else{
        printf("Corrigir BUG");
    }

//                    ---------------------------------------- FIM TERCEIRA FASE ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- QUARTA FASE ----------------------------------------
    proximaMissao = aleatorio();
    //proximaMissao = 4; //TESTAR MISS�O SEPARADAS
    
    switch(proximaMissao){ //Defini��o aleat�ria da Pr�xima Miss�o do Jogo
        case 1: //Miss�o 01 - Sequestro
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Temos uma situa��o de emerg�ncia. Um grupo de criminosos perigosos mant�m ref�ns em um local espec�fico da cidade. As vidas dessas pessoas est�o em perigo, e precisamos da sua ajuda para resgat�-las.\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
            printf("\nDigite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = sequestro(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
            
            break;
        
        case 2: //Miss�o 02 - Gangues
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "A cidade est� sob a amea�a das gangues rivais que espalham o caos e a viol�ncia em suas disputas territoriais. � hora de agir! Como o defensor aracn�deo da justi�a, voc� � convocado para combater essas gangues e trazer a paz de volta �s ruas.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = gangue(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
        
        case 6:    
        case 3: //Miss�o 03 - Rob�s
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma grave amea�a se aproxima! Uma horda de rob�s controlados por um vil�o sinistro que est� planejando invadir uma �rea vital da cidade. A situa��o exige sua imediata interven��o para proteger os cidad�os e preservar a seguran�a da regi�o.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = invasao(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
            
        case 4: //Miss�o 04 - Batalha nas Alturas
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma misteriosa figura voadora est� aterrorizando a cidade, espalhando medo entre os cidad�os, detenha-o enquanto n�o cause danos maiores!\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = batalhaAltura(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
        
            break;
            
        case 5: //Miss�o 05 - Gato preso
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma situa��o de emerg�ncia requer sua aten��o imediata! Uma idosa est� precisando de sua ajuda com seu amado gato que est� preso no topo de uma �rvore alta, localizada na Rua Tranquilidade, pr�xima ao Parque Central.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Ajudar cidad�o\n");    
            printf("2 - Ignorar pedido\n");
            
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                vitoria = salvarGato();
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve ignorar o pedido de ajuda de um cidad�o.\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 4){ //Reputa��o (-10)
                reputacao = reputacao - 10;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            
            break;
    }
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
    vitoria = 0;
    
    system("Pause");
    system("cls");
    
    bonus = bonusVida(vida);
    //printf("Bonus: %d", bonus);
    
    if (bonus == 1){
        printf("\nVida Restaurada: 100%\n\n");
        vida = 100;
        
        system("Pause");
        system("cls");
    }else if (bonus == 0){
    
    }else{
        printf("Corrigir BUG");
    }

//                    ---------------------------------------- FIM QUARTA FASE ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Loja
    if (moedas > 0){
        strcpy(texto, "Aproveite que a cidade est� livre de perigos para visitar a loja dos her�is!\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
        printf("1- Entrar na loja\n");
        printf("2- Sair da sala\n");
        
        do{
            scanf("%d", &entrarLoja);  
            if((entrarLoja < 1)||(entrarLoja > 2)){
            printf("Op��o Inv�lida! Digite novamente...\n");
            }
        }while((entrarLoja < 1)||(entrarLoja > 2));
        
        switch(entrarLoja){
            case 1:
            do{
                strcpy(texto, "O que voc� deseja ver agora?\n"); 
                tamanho = strlen(texto);
                for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
                }               
                printf("1- Kit cura\n");
                printf("2- Melhorar Habilidades\n");
                printf("3- Sair da loja\n\n");
                
                do{
                    scanf("%d", &entrarSair);  
                    if((entrarSair < 1)||(entrarSair >= 4)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                    }
                }while((entrarSair < 1)||(entrarSair > 4));
                itemLoja = entrarSair;
                if (itemLoja == 1){
                    system("cls");
                    printf("Suas moedas: %d\n", moedas);
                    printf("Sua vida: %d\n\n", vida);
                    printf("1- Cura (+20) = 40 moedas\n");
                    printf("2- Cura (+30) = 50 moedas\n");
                    printf("3- Cura Total = 100 moedas\n");
                    printf("4- Sair da loja\n");
                    do{
                        scanf("%d", &itemLoja);  
                        if((itemLoja < 1)||(itemLoja > 4)){
                        printf("Op��o Inv�lida! Digite novamente...\n");
                        }
                    }while((itemLoja < 1)||(itemLoja > 4));
                    
                    switch(itemLoja){
                        case 1:
                            if (vida <= 80){
                                if (moedas >= 40){
                                    vida = vida + 20;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 40;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if ((vida > 80) && (vida < 100)){
                                if (moedas >= 40){
                                    vida = 100;
                                    moedas = moedas - 40;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 40){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 2:
                            if (vida <= 70){
                                if (moedas >= 50){
                                    vida = vida + 30;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 50;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if ((vida > 70) && (vida < 100)){
                                if (moedas >= 50){
                                    vida = 100;
                                    moedas = moedas - 50;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 50){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 3:
                            if (vida < 100){
                                if (moedas >= 100){
                                    vida = 100;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 100;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 100){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                        
                        break;
                        
                        case 4:
                            printf("Obrigada por visitar nossa loja!\n\n");
                        break;
                        
                        default:
                            printf("Corrigir BUG");
                        
                    }
                    printf("Suas moedas: %d\n\n", moedas);
                    printf("Vida: %d\n\n", vida);
                    system("Pause");
                    system("cls");
                }else if (itemLoja == 2){
                    system("cls");
                    printf("Suas moedas: %d\n\n", moedas);
                    printf("1- Habilidade de For�a (+3) = 50 moedas\n");
                    printf("2- Habilidade de Defesa (+2) = 50 moedas\n");
                    printf("3- Habilidade de Esquiva (+1) = 100 moedas\n");
                    printf("4- Sair da loja\n");
                    do{
                        scanf("%d", &itemLoja);  
                        if((itemLoja < 1)||(itemLoja > 4)){
                        printf("Op��o Inv�lida! Digite novamente...\n");
                        }
                    }while((itemLoja < 1)||(itemLoja > 4));
                    
                    switch(itemLoja){
                        case 1:
                            if (moedas >= 50){
                                forca = forca + 3;
                                moedas = moedas - 50;
                                printf("\nFor�a (+3) total: %d\n\n", forca);
                            }else {
                                    printf("\nSaldo insuficiente.\n\n");
                            }
                            
                        break;
                        
                        case 2:
                            if (defesa >= 20){
                                printf("\nVoc� atingiu a defesa m�xima\n");
                                printf("\nDefesa: %d\n\n", defesa);
                            }else if (defesa < 20){
                                if (moedas >= 50){
                                    defesa = defesa + 2;
                                    moedas = moedas - 50;
                                    printf("\nDefesa (+2) total: %d\n\n", defesa);
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 3:
                            if (moedas >= 100){
                                esquiva = esquiva + 1;
                                moedas = moedas - 100;
                                printf("\nEsquiva (+1) total: %d\n\n", esquiva);
                            }else {
                                    printf("\nSaldo insuficiente.\n\n");
                            }
                            
                        break;
                        
                        case 4:
                            printf("Obrigada por visitar nossa loja!\n\n");
                        break;
                        
                        default:
                            printf("\nCorrigir BUG\n\n");
                        break;
                    }
                    printf("Suas moedas: %d\n\n", moedas);
                   
                    system("Pause");
                    system("cls");
                }
            
            }while(entrarSair != 3);  
            system("cls");  
            break;
            
            case 2:
                printf("Fique a vontade para visitar nossa loja quando quiser. At� mais!\n\n");
                
                system("Pause");
                system("cls");
            break;
        }
        
    }



//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- VIL�O 2 DUENDE VERDE ----------------------------------------

    printf("Alerta de emerg�ncia! Spider %s,", nomeHeroi);
    
    strcpy(texto, " Precisamos da sua ajuda imediatamente! \nO Duende Verde est� atacando a cidade, causando caos e destrui��o por onde passa. Ele est� lan�ando bombas explosivas e semeando o medo entre os cidad�os. A cidade precisa de voc� para det�-lo e impedir mais danos.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
      
    
    printf("Spider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Ol�, Duende Verde. Parece que nossos caminhos se cruzaram novamente.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para verde
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Duende Verde: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Ah, o pequeno aracn�deo insolente. Sempre acreditando que pode me deter.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Spider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Eu j� derrotei voc� antes, Duende Verde, e farei isso de novo. Seus planos malignos n�o t�m espa�o nesta cidade.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para verde
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Duende Verde: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Voc� n�o entende. Eu sou a personifica��o do caos. Nenhum her�i pode me deter.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para verde
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Duende Verde: "); 
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Sua teimosia ser� sua ru�na, her�i. Prepare-se para enfrentar meu novo arsenal!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    system("Pause");
    system("cls");
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    
    meuVetor = boss(nivel, forca, vida, defesa);
    vitoria = meuVetor[1];
    vida = meuVetor[2];
    
    //vitoria = 5 | +15 Reputa��o | +150 Moedas
    if (vitoria == 5){
        reputacao = reputacao + 15;
        moedas = moedas + 150;
        nivel++;
    }else if (vitoria == 0){ 
        // Alterar cor do texto para verde
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);       
        strcpy(texto, "Duende Verde: Sua resist�ncia � admir�vel, mas suas habilidades n�o s�o p�reo para o verdadeiro poder do Duende Verde. Voc� foi derrotado, seu pequeno inseto! A cidade conhecer� o dom�nio absoluto do caos, e sua derrota ser� lembrada como um exemplo de impot�ncia diante do meu reinado!\n\n"); 
        tamanho = strlen(texto);
        for (int i = 0; i < tamanho; i++) {
            printf("%c", texto[i]);
            Sleep(20); 
        }
        printf("FIM DE JOGO\n\n");
        system("Pause");
        return 0;
    }else {
        printf("Corrigir BUG");
    }
    
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    printf("\nSpider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Duende Verde, sua maldade e destrui��o chegaram ao fim! A justi�a prevaleceu sobre sua loucura. Voc� foi derrotado e n�o representar� mais uma amea�a para esta cidade. Agora � hora de encarar as consequ�ncias de suas a��es e enfrentar a justi�a! \n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para verde
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); 
    printf("Duende Verde: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Oh, voc� pode ter vencido desta vez, mas saiba que isso n�o acabou. A vingan�a est� entrela�ada em minhas veias e eu sempre voltarei. A cidade ainda sentir� meu poder e meu riso ecoar� em seus pesadelos. Prepare-se, pois a pr�xima vez ser� a sua derrota!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    system("Pause");
    system("cls");
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Parab�ns, Spider %s, por derrotar o terr�vel Duende Verde! \n\n", nomeHeroi);
    Sleep(2000);
    strcpy(texto, "Voc� desbloqueou uma nova habilidade incr�vel, a habilidade de LAN�AR BOMBINHAS! Agora, com esse poderoso recurso em seu arsenal, voc� pode enfrentar desafios ainda maiores e deter amea�as com ainda mais efic�cia.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    
    bonus = bonusVida(vida);
    if (bonus == 1){
        printf("\nVida Restaurada: 100\n\n");
        vida = 100;
        system("Pause");
        system("cls");
    }else if (bonus == 0){
        printf("\nB�nus de Vida: 50\n\n");
        if (vida <= 50){
            vida = vida + 50;
        }else {
            vida = 100;
        }
    }else{
        printf("Corrigir BUG");
    }
    
    printf("Vida: %d\n\n", vida);
    system("Pause");
    system("cls");

//                    ---------------------------------------- FIM VIL�O 2 ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- QUINTA FASE ----------------------------------------
    proximaMissao = aleatorio();
    //proximaMissao = 4; //TESTAR MISS�O SEPARADAS
    
    switch(proximaMissao){ //Defini��o aleat�ria da Pr�xima Miss�o do Jogo
        case 1: //Miss�o 01 - Sequestro
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Temos uma situa��o de emerg�ncia. Um grupo de criminosos perigosos mant�m ref�ns em um local espec�fico da cidade. As vidas dessas pessoas est�o em perigo, e precisamos da sua ajuda para resgat�-las.\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
            printf("\nDigite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = sequestro(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
            
            break;
        
        case 2: //Miss�o 02 - Gangues
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "A cidade est� sob a amea�a das gangues rivais que espalham o caos e a viol�ncia em suas disputas territoriais. � hora de agir! Como o defensor aracn�deo da justi�a, voc� � convocado para combater essas gangues e trazer a paz de volta �s ruas.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = gangue(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
        
        case 6:    
        case 3: //Miss�o 03 - Rob�s
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma grave amea�a se aproxima! Uma horda de rob�s controlados por um vil�o sinistro que est� planejando invadir uma �rea vital da cidade. A situa��o exige sua imediata interven��o para proteger os cidad�os e preservar a seguran�a da regi�o.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = invasao(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
            
        case 4: //Miss�o 04 - Batalha nas Alturas
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma misteriosa figura voadora est� aterrorizando a cidade, espalhando medo entre os cidad�os, detenha-o enquanto n�o cause danos maiores!\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = batalhaAltura(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
        
            break;
            
        case 5: //Miss�o 05 - Gato preso
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma situa��o de emerg�ncia requer sua aten��o imediata! Uma idosa est� precisando de sua ajuda com seu amado gato que est� preso no topo de uma �rvore alta, localizada na Rua Tranquilidade, pr�xima ao Parque Central.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Ajudar cidad�o\n");    
            printf("2 - Ignorar pedido\n");
            
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                vitoria = salvarGato();
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve ignorar o pedido de ajuda de um cidad�o.\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 4){ //Reputa��o (-10)
                reputacao = reputacao - 10;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            
            break;
    }
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
    vitoria = 0;
    
    system("Pause");
    system("cls");
    
    bonus = bonusVida(vida);
    //printf("Bonus: %d", bonus);
    
    if (bonus == 1){
        printf("\nVida Restaurada: 100%\n\n");
        vida = 100;
        
        system("Pause");
        system("cls");
    }else if (bonus == 0){
    
    }else{
        printf("Corrigir BUG");
    }

//                    ---------------------------------------- FIM QUINTA FASE ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- SEXTA FASE ----------------------------------------
    proximaMissao = aleatorio();
    //proximaMissao = 4; //TESTAR MISS�O SEPARADAS
    
    switch(proximaMissao){ //Defini��o aleat�ria da Pr�xima Miss�o do Jogo
        case 1: //Miss�o 01 - Sequestro
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Temos uma situa��o de emerg�ncia. Um grupo de criminosos perigosos mant�m ref�ns em um local espec�fico da cidade. As vidas dessas pessoas est�o em perigo, e precisamos da sua ajuda para resgat�-las.\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
            printf("\nDigite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = sequestro(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
            
            break;
        
        case 2: //Miss�o 02 - Gangues
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "A cidade est� sob a amea�a das gangues rivais que espalham o caos e a viol�ncia em suas disputas territoriais. � hora de agir! Como o defensor aracn�deo da justi�a, voc� � convocado para combater essas gangues e trazer a paz de volta �s ruas.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = gangue(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
        
        case 6:    
        case 3: //Miss�o 03 - Rob�s
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma grave amea�a se aproxima! Uma horda de rob�s controlados por um vil�o sinistro que est� planejando invadir uma �rea vital da cidade. A situa��o exige sua imediata interven��o para proteger os cidad�os e preservar a seguran�a da regi�o.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = invasao(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
            vitoria = 0;
        
            break;
            
        case 4: //Miss�o 04 - Batalha nas Alturas
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma misteriosa figura voadora est� aterrorizando a cidade, espalhando medo entre os cidad�os, detenha-o enquanto n�o cause danos maiores!\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Aceitar Desafio\n");    
            printf("2 - Ignorar Miss�o\n");
    
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                meuVetor = batalhaAltura(forca, defesa, vida, esquiva, nivel);
                vitoria = meuVetor[1];
                vida = meuVetor[2];
                
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve fugir da batalha\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
        
            break;
            
        case 5: //Miss�o 05 - Gato preso
            printf("ATEN��O, %s!\n", nomeHeroi);
            
            strcpy(texto, "Uma situa��o de emerg�ncia requer sua aten��o imediata! Uma idosa est� precisando de sua ajuda com seu amado gato que est� preso no topo de uma �rvore alta, localizada na Rua Tranquilidade, pr�xima ao Parque Central.\n\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            printf("Digite sua op��o: \n");
            printf("1 - Ajudar cidad�o\n");    
            printf("2 - Ignorar pedido\n");
            
            do{
                scanf("%d", &missao);  
                if((missao < 1)||(missao > 2)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                }
            }while((missao < 1)||(missao > 2));
            
            system("cls"); //Limpa Tela
            
            if (missao == 1){ //Caso Aceite a Miss�o
                vitoria = salvarGato();
            }else if(missao == 2){ //Caso Ignore a Miss�o 
                printf("Que pena! Um her�i n�o deve ignorar o pedido de ajuda de um cidad�o.\n");
                reputacao = reputacao - 10;
                printf("Reputacao (-10)\n");
            }
            
            if(reputacao < 70){
                printf("Fim de Jogo! Sua reputa��o est� baixa demais");
                system("Pause");
                return 0;
            }
            
            if (vitoria == 0){
                //Op��o em branco caso o jogador resolva n�o aceitar miss�o
            }else if (vitoria == 1){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 2){ //Reputa��o (+5) | Moedas (+50)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 50;
            }else if (vitoria == 3){ //Reputa��o (+5) | Moedas (+100)
                if (reputacao >= 100){
                    reputacao = 100;
                }else{
                    reputacao = reputacao + 5;
                }
                moedas = moedas + 100;
            }else if (vitoria == 4){ //Reputa��o (-10)
                reputacao = reputacao - 10;
            }else {
                //conferir BUG
                printf("ERRO! CORRIGIR BUG");
            }
            
            break;
    }
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    // vitoria = 0 para evitar erro na pr�xima partida caso o jogador resolva pular a batalha
    vitoria = 0;
    
    system("Pause");
    system("cls");
    
    bonus = bonusVida(vida);
    //printf("Bonus: %d", bonus);
    
    if (bonus == 1){
        printf("\nVida Restaurada: 100%\n\n");
        vida = 100;
        
        system("Pause");
        system("cls");
    }else if (bonus == 0){
    
    }else{
        printf("Corrigir BUG");
    }

//                    ---------------------------------------- FIM SEXTA FASE ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Loja
    if (moedas > 0){
        strcpy(texto, "Aproveite que a cidade est� livre de perigos para visitar a loja dos her�is!\n"); 
            tamanho = strlen(texto);
            for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
            }
            
        printf("1- Entrar na loja\n");
        printf("2- Sair da sala\n");
        
        do{
            scanf("%d", &entrarLoja);  
            if((entrarLoja < 1)||(entrarLoja > 2)){
            printf("Op��o Inv�lida! Digite novamente...\n");
            }
        }while((entrarLoja < 1)||(entrarLoja > 2));
        
        switch(entrarLoja){
            case 1:
            do{
                strcpy(texto, "O que voc� deseja ver agora?\n"); 
                tamanho = strlen(texto);
                for (int i = 0; i < tamanho; i++) {
                    printf("%c", texto[i]);
                    Sleep(20); 
                }               
                printf("1- Kit cura\n");
                printf("2- Melhorar Habilidades\n");
                printf("3- Sair da loja\n\n");
                
                do{
                    scanf("%d", &entrarSair);  
                    if((entrarSair < 1)||(entrarSair >= 4)){
                    printf("Op��o Inv�lida! Digite novamente...\n");
                    }
                }while((entrarSair < 1)||(entrarSair > 4));
                itemLoja = entrarSair;
                if (itemLoja == 1){
                    system("cls");
                    printf("Suas moedas: %d\n", moedas);
                    printf("Sua vida: %d\n\n", vida);
                    printf("1- Cura (+20) = 40 moedas\n");
                    printf("2- Cura (+30) = 50 moedas\n");
                    printf("3- Cura Total = 100 moedas\n");
                    printf("4- Sair da loja\n");
                    do{
                        scanf("%d", &itemLoja);  
                        if((itemLoja < 1)||(itemLoja > 4)){
                        printf("Op��o Inv�lida! Digite novamente...\n");
                        }
                    }while((itemLoja < 1)||(itemLoja > 4));
                    
                    switch(itemLoja){
                        case 1:
                            if (vida <= 80){
                                if (moedas >= 40){
                                    vida = vida + 20;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 40;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if ((vida > 80) && (vida < 100)){
                                if (moedas >= 40){
                                    vida = 100;
                                    moedas = moedas - 40;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 40){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 2:
                            if (vida <= 70){
                                if (moedas >= 50){
                                    vida = vida + 30;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 50;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if ((vida > 70) && (vida < 100)){
                                if (moedas >= 50){
                                    vida = 100;
                                    moedas = moedas - 50;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 50){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 3:
                            if (vida < 100){
                                if (moedas >= 100){
                                    vida = 100;
                                    printf("\n\nVida Restaurada!\n\n");
                                    moedas = moedas - 100;
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }else if (vida == 100){ 
                                if (moedas >= 100){
                                    printf("\n\nSua vida j� est� no m�ximo!\n\n");
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                        
                        break;
                        
                        case 4:
                            printf("Obrigada por visitar nossa loja!\n\n");
                        break;
                        
                        default:
                            printf("Corrigir BUG");
                        
                    }
                    printf("Suas moedas: %d\n\n", moedas);
                    printf("Vida: %d\n\n", vida);
                    system("Pause");
                    system("cls");
                }else if (itemLoja == 2){
                    system("cls");
                    printf("Suas moedas: %d\n\n", moedas);
                    printf("1- Habilidade de For�a (+3) = 50 moedas\n");
                    printf("2- Habilidade de Defesa (+2) = 50 moedas\n");
                    printf("3- Habilidade de Esquiva (+1) = 100 moedas\n");
                    printf("4- Sair da loja\n");
                    do{
                        scanf("%d", &itemLoja);  
                        if((itemLoja < 1)||(itemLoja > 4)){
                        printf("Op��o Inv�lida! Digite novamente...\n");
                        }
                    }while((itemLoja < 1)||(itemLoja > 4));
                    
                    switch(itemLoja){
                        case 1:
                            if (moedas >= 50){
                                forca = forca + 3;
                                moedas = moedas - 50;
                                printf("\nFor�a (+3) total: %d\n\n", forca);
                            }else {
                                    printf("\nSaldo insuficiente.\n\n");
                            }
                            
                        break;
                        
                        case 2:
                            if (defesa >= 20){
                                printf("\nVoc� atingiu a defesa m�xima\n");
                                printf("\nDefesa: %d\n\n", defesa);
                            }else if (defesa < 20){
                                if (moedas >= 50){
                                    defesa = defesa + 2;
                                    moedas = moedas - 50;
                                    printf("\nDefesa (+2) total: %d\n\n", defesa);
                                }else {
                                    printf("\nSaldo insuficiente.\n\n");
                                }
                            }
                            
                        break;
                        
                        case 3:
                            if (moedas >= 100){
                                esquiva = esquiva + 1;
                                moedas = moedas - 100;
                                printf("\nEsquiva (+1) total: %d\n\n", esquiva);
                            }else {
                                    printf("\nSaldo insuficiente.\n\n");
                            }
                            
                        break;
                        
                        case 4:
                            printf("Obrigada por visitar nossa loja!\n\n");
                        break;
                        
                        default:
                            printf("\nCorrigir BUG\n\n");
                        break;
                    }
                    printf("Suas moedas: %d\n\n", moedas);
                   
                    system("Pause");
                    system("cls");
                }
            
            }while(entrarSair != 3);  
            system("cls");  
            break;
            
            case 2:
                printf("Fique a vontade para visitar nossa loja quando quiser. At� mais!\n\n");
                
                system("Pause");
                system("cls");
            break;
        }
        
    }


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//                    ---------------------------------------- VIL�O 3 DOUTOR OCTOPOS ----------------------------------------


    strcpy(texto, "Alerta de emerg�ncia! Precisamos da sua ajuda imediatamente! O Doutor Octopus est� causando caos e destrui��o na cidade. Suas garras mec�nicas est�o atacando indiscriminadamente, colocando a vida dos cidad�os em perigo.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    printf("Spider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Doutor Octopus, voc� realmente n�o desiste, n�o �? Est� na hora de enfrentar as consequ�ncias dos seus atos!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para azul
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("Doutor Octopus: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Sempre se metendo em meus planos! Voc� n�o entende a grandiosidade de minhas inven��es. Eu vou derrot�-lo desta vez!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Spider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Suas tentativas de dominar a cidade nunca v�o dar certo, Octavius. Estou aqui para garantir que a justi�a prevale�a sobre sua loucura cient�fica.\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para azul
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("Doutor Octopus: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Veremos quem sair� vitorioso no final. A batalha est� apenas come�ando!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
        
    system("Pause");
    system("cls");
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    
    meuVetor = boss(nivel, forca, vida, defesa);
    vitoria = meuVetor[1];
    vida = meuVetor[2];
    
    //vitoria = 5 | +15 Reputa��o | +150 Moedas
    if (vitoria == 5){
        reputacao = reputacao + 15;
        moedas = moedas + 150;
        nivel++;
    }else if (vitoria == 0){
        // Alterar cor do texto para azul
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        strcpy(texto, "Doutor Octopus: Seus esfor�os foram em v�o! Minhas garras mec�nicas provaram sua superioridade sobre sua teia fr�gil. Voc� foi derrotado desta vez, e a cidade logo testemunhar� minha ascens�o como o verdadeiro mestre da ci�ncia e do caos!\n\n"); 
        tamanho = strlen(texto);
        for (int i = 0; i < tamanho; i++) {
            printf("%c", texto[i]);
            Sleep(20); 
        }
        printf("FIM DE JOGO\n\n");
        
        system("Pause");
        return 0;
    }else {
        printf("Corrigir BUG");
    }
    
    printf("\n\nTotal reputa��o: %d\n", reputacao);
    printf("Total moedas: %d\n", moedas);
    printf("Vida: %d\n\n", vida);
    
    printf("\nSpider %s: ", nomeHeroi);
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Doutor Octopus, seus planos malignos foram frustrados mais uma vez! A for�a da justi�a e do hero�smo prevaleceu sobre suas garras mec�nicas. Voc� foi derrotado e seus atos destrutivos chegaram ao fim. \n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    // Alterar cor do texto para azul
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("Doutor Octopus: ");
    // Restaurar a cor padr�o
    SetConsoleTextAttribute(hConsole, corPadrao);
    strcpy(texto, "Ah,  voc� pode ter me derrotado desta vez, mas lembre-se bem, a ci�ncia nunca � derrotada. Minha vingan�a ser� engenhosa e implac�vel. Ainda ver� que as garras do Octopus sempre encontram um caminho de volta. Esta n�o � o fim, � apenas o come�o!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    system("Pause");
    system("cls");
    
    // Alterar cor do texto para vermelho
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    
    printf("Parab�ns, Spider %s, por derrotar o terr�vel Doutor Octopos! \n\n", nomeHeroi);
    strcpy(texto, "Homem Aranha: Valeu, amigo! A cidade toda t� te devendo uma, parceiro. Voc� mandou ver e livrou a gente de todos os perigos que estavam rondando por a�. Seu esp�rito heroico e coragem s�o de tirar o chap�u. Agradecemos de cora��o por manter nossa cidade segura e por nos mostrar o verdadeiro significado de ser um her�i. Voc� � demais!\n\n"); 
    tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
        Sleep(20); 
    }
    
    system("Pause");
    system("cls");


//                    ---------------------------------------- FIM VIL�O 3 ----------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
    
             
    system ("Pause");
    return 0;
}
