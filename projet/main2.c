#include <stdio.h>
#include <string.h>
#include<stdlib.h>


int main(){
    char nom[30],ch;
    char entreprise[10]; 
    int vente,achat;
    int actionApple,actionAmazon,actionAlphabet,actionFacebook,actionMicrosoft;
    actionApple=actionAmazon=actionAlphabet=actionFacebook=actionMicrosoft=0;
    int jour, i; //jour = numéro du jour de novembre
    char ent[5][10]; //ent sera la liste d'entreprises qui intéressent le joueur. Elle peut contenir au maximum 5 entreprises (Amazon, Google, etc) de 10 caractères
    float coursStock=0,valeurPortefeuille=0;
    float cashinitial;
    float cash,ROI;
    float coursStockAlphabet,coursStockAmazon,coursStockApple,coursStockMicrosoft,coursStockFacebook;
    



    //Données Google
    char url1[400];

    FILE *instructionFile1;
    char instruction1[200];
    instructionFile1 = fopen("instruction.instr", "rb");
    fgets(instruction1,200,instructionFile1);
    fclose(instructionFile1);

    FILE * tokenFile1;
    char token1[60];

    system("wget --no-check-certificate --save-cookies=cookie.txt https://finance.yahoo.com/quote/GOOG/?p=GOOG -O crumb.store");
    system(instruction1);

    printf("Token Saved\n");

    tokenFile1 = fopen("crumb.token", "rb");
    fgets(token1,60,tokenFile1);

    printf("Token is %s\n", token1);
    
    sprintf(url1, "wget --no-check-certificate --load-cookies=cookie.txt \"https://query1.finance.yahoo.com/v7/finance/download/GOOG?period1=1509577200&period2=1512082800&interval=1d&events=history&crumb=%s\" -O GOOG.csv", token1);
    system(url1);

    fclose(tokenFile1);


//données Amazon

    char url2[400];

    FILE *instructionFile2;
    char instruction2[200];
    instructionFile2 = fopen("instruction.instr", "rb");
    fgets(instruction2,200,instructionFile2);
    fclose(instructionFile2);

    FILE * tokenFile2;
    char token2[60];

    system("wget --no-check-certificate --save-cookies=cookie.txt https://finance.yahoo.com/quote/AMZN/?p=AMZN -O crumb.store");
    system(instruction2);

    printf("Token Saved\n");

    tokenFile2 = fopen("crumb.token", "rb");
    fgets(token2,60,tokenFile2);

    printf("Token is %s\n", token2);
    
    sprintf(url2, "wget --no-check-certificate --load-cookies=cookie.txt \"https://query1.finance.yahoo.com/v7/finance/download/AMZN?period1=1509577200&period2=1512082800&interval=1d&events=history&crumb=%s\" -O AMAZON.csv", token2);
    system(url2);

    fclose(tokenFile2);

    


// Données Facebook
    char url3[400];

    FILE *instructionFile3;
    char instruction3[200];
    instructionFile3 = fopen("instruction.instr", "rb");
    fgets(instruction3,200,instructionFile3);
    fclose(instructionFile3);

    FILE * tokenFile3;
    char token3[60];

    system("wget --no-check-certificate --save-cookies=cookie.txt https://finance.yahoo.com/quote/FB/?p=FB -O crumb.store");
    system(instruction3);

    printf("Token Saved\n");

    tokenFile3 = fopen("crumb.token", "rb");
    fgets(token3,60,tokenFile3);

    printf("Token is %s\n", token3);
    
    sprintf(url3, "wget --no-check-certificate --load-cookies=cookie.txt \"https://query1.finance.yahoo.com/v7/finance/download/FB?period1=1509577200&period2=1512082800&interval=1d&events=history&crumb=%s\" -O FACEBOOK.csv", token3);
    system(url3);

    fclose(tokenFile3);

    


//Données Apple
    char url4[400];

    FILE *instructionFile4;
    char instruction4[200];
    instructionFile4 = fopen("instruction.instr", "rb");
    fgets(instruction4,200,instructionFile4);
    fclose(instructionFile4);

    FILE * tokenFile4;
    char token4[60];

    system("wget --no-check-certificate --save-cookies=cookie.txt https://finance.yahoo.com/quote/AAPL/?p=AAPL -O crumb.store");
    system(instruction4);

    printf("Token Saved\n");

    tokenFile4 = fopen("crumb.token", "rb");
    fgets(token4,60,tokenFile4);

    printf("Token is %s\n", token4);
    
    sprintf(url4, "wget --no-check-certificate --load-cookies=cookie.txt \"https://query1.finance.yahoo.com/v7/finance/download/AAPL?period1=1511282030&period2=1513874030&interval=1d&events=history&crumb=%s\" -O APPLE.csv", token4);
    system(url4);

    fclose(tokenFile4);



//Données microsoft
    char url5[400];

    FILE *instructionFile5;
    char instruction5[200];
    instructionFile5 = fopen("instruction.instr", "rb");
    fgets(instruction5,200,instructionFile5);
    fclose(instructionFile5);

    FILE * tokenFile5;
    char token5[60];

    system("wget --no-check-certificate --save-cookies=cookie.txt https://finance.yahoo.com/quote/MFST/?p=MSFT -O crumb.store");
    system(instruction5);

    printf("Token Saved\n");

    tokenFile5 = fopen("crumb.token", "rb");
    fgets(token5,60,tokenFile5);

    printf("Token is %s\n", token5);
    
    sprintf(url5, "wget --no-check-certificate --load-cookies=cookie.txt \"https://query1.finance.yahoo.com/v7/finance/download/MSFT?period1=1511282087&period2=1513874087&interval=1d&events=history&crumb=%s\" -O MICROSOFT.csv", token5);
    system(url5);

    fclose(tokenFile5);




    char tabCoursGoogle[60][50]; //on crée un tableau contenant les dates et les cours journaliers à la clôture correspondants pour Google

    FILE *input1;
    
    input1=fopen("GOOG.csv","r");

    char ligne1[500]; //ligne1 lit ligne par ligne le fichier GOOG.csv
    
    const char s[2] = ",";
    char *token11;
    int i1=0;
   
    fgets(ligne1,500, input1); //ligne1 commence par stocker la première ligne du CSV
    while(fgets(ligne1,500,input1)!=NULL){
      /* get the first token */
        
        token11 = strtok(ligne1, s); // ici strtok brise une chaîne de caractères séparés par une virgule
        
        while( token11 != NULL ) { //tant qu'on ne parvient pas à la fin de la ligne
            
            strcpy(tabCoursGoogle[i],token11); //on copie chaque token1 dans le tableau prévu à cet effet
            i1=i1+1; //le tableau se remplit au fur et à mesure
            
            token11 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token11 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token11 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token11 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token11 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
        
        }

    }
   

char tabCoursAmazon[60][50]; //on crée un tableau contenant les dates et les cours journaliers à la clôture correspondants pour Amazon

    FILE *input2;
    
    input2=fopen("AMAZON.csv","r");

    char ligne2[500]; //ligne1 lit ligne par ligne le fichier GOOG.csv
    char *token12;
    int i2=0;
   
    fgets(ligne2,500, input2); //ligne1 commence par stocker la première ligne du CSV
    while(fgets(ligne2,500,input2)!=NULL){
      /* get the first token */
        
        token12 = strtok(ligne2, s); // ici strtok brise une chaîne de caractères séparés par une virgule
        
        while( token12 != NULL ) { //tant qu'on ne parvient pas à la fin de la ligne
            
            strcpy(tabCoursAmazon[i],token12); //on copie chaque token1 dans le tableau prévu à cet effet
            i2=i2+1; //le tableau se remplit au fur et à mesure
            
            token12 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token12 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token12 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token12 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token12 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
        
        }

    }

    char tabCoursFacebook[60][50]; //on crée un tableau contenant les dates et les cours journaliers à la clôture correspondants pour Facebook

    FILE *input3;
    
    input3=fopen("FACEBOOK.csv","r");

    char ligne3[500]; //ligne1 lit ligne par ligne le fichier GOOG.csv
    char *token13;
    int i3=0;
   
    fgets(ligne3,500, input3); //ligne1 commence par stocker la première ligne du CSV
    while(fgets(ligne3,500,input3)!=NULL){
      /* get the first token */
        
        token13 = strtok(ligne3, s); // ici strtok brise une chaîne de caractères séparés par une virgule
        
        while( token13 != NULL ) { //tant qu'on ne parvient pas à la fin de la ligne
            
            strcpy(tabCoursFacebook[i],token13); //on copie chaque token1 dans le tableau prévu à cet effet
            i3=i3+1; //le tableau se remplit au fur et à mesure
            
            token13 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token13 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token13 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token13 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token13 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
        
        }

    }

char tabCoursApple[60][50]; //on crée un tableau contenant les dates et les cours journaliers à la clôture correspondants pour Apple

    FILE *input4;
    
    input4=fopen("APPLE.csv","r");

    char ligne4[500]; //ligne1 lit ligne par ligne le fichier APPLE.csv
    char *token14;
    int i4=0;
   
    fgets(ligne4,500, input4); //ligne1 commence par stocker la première ligne du CSV
    while(fgets(ligne4,500,input4)!=NULL){
      /* get the first token */
        
        token14 = strtok(ligne4, s); // ici strtok brise une chaîne de caractères séparés par une virgule
        
        while( token14 != NULL ) { //tant qu'on ne parvient pas à la fin de la ligne
            
            strcpy(tabCoursApple[i],token14); //on copie chaque token1 dans le tableau prévu à cet effet
            i4=i4+1; //le tableau se remplit au fur et à mesure
            
            token14 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token14 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token14 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token14 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token14 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
        
        }

    }


    char tabCoursMicrosoft[60][50]; //on crée un tableau contenant les dates et les cours journaliers à la clôture correspondants pour Microsoft

    FILE *input5;
    
    input5=fopen("AMAZON.csv","r");

    char ligne5[500]; //ligne1 lit ligne par ligne le fichier MICROSOFT.csv
    char *token15;
    int i5=0;
   
    fgets(ligne5,500, input5); //ligne1 commence par stocker la première ligne du CSV
    while(fgets(ligne5,500,input5)!=NULL){
      /* get the first token */
        
        token15 = strtok(ligne5, s); // ici strtok brise une chaîne de caractères séparés par une virgule
        
        while( token15 != NULL ) { //tant qu'on ne parvient pas à la fin de la ligne
            
            strcpy(tabCoursMicrosoft[i],token15); //on copie chaque token1 dans le tableau prévu à cet effet
            i5=i5+1; //le tableau se remplit au fur et à mesure
            
            token15 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token15 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token15 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token15 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
            token15 = strtok(NULL, s); //remplace la prochaine virgule trouvée par NULL pour ignorer la valeur
        
        }

    }



    
    char filename[20];
    FILE *output;
    printf("Veuillez choisir un nom de fichier. \n");
    scanf("%s",filename);
    output=fopen(filename,"w");
    

    printf("Veuillez indiquer le nom du joueur. \n");
    scanf("%s",nom);
    fprintf(output,"Résultats du joueur %s \n",nom);
    printf("Veuillez indiquer le montant initial dont vous disposez. \n");
    scanf("%f",&cash);
    cashinitial=cash;
    

    jour=1; // on commence le 1er novembre
    while(jour<=2){ //tant qu'on est avant le 30/11
        //on exclut les weekends de novembre qui sont les 4/11 et 5/11 etc
        while (jour%7==4 ||jour%7==5){
            jour++;
        } 

        printf("Jour %d. \nPour rappel, votre composition actuelle de portefeuille est : Alphabet %d, Amazon %d, Facebook %d, Apple %d, Microsoft %d.\n Vous disposez de %f. \n",jour,actionAlphabet,actionAmazon,actionFacebook,actionApple,actionMicrosoft,cash);
        fprintf(output,"\n\nRésultats du jour %d :\n\n",jour);
            
        printf("Nous sommes le jour %d. Vous avez le choix parmi Alphabet, Amazon, Facebook, Apple et Microsoft. Spécifiez une entreprise. Saisissez Fini pour terminer. \n",jour);
        scanf("%s",entreprise);
        strcpy(ent[0],entreprise); //la liste ent stocke la première entreprise choisie par le joueur

        i=1; 
        while(strcmp(entreprise,"Fini")!=0){
            while((ch = getchar()) != '\n');
            printf("Spécifiez une entreprise. \n");
            scanf("%s",entreprise);
            if(strcmp(entreprise,"Fini")!=0){
                strcpy(ent[i],entreprise);
            }
            i=i+1;
            //on remplit la liste ent avec les choix de l'utilisateur
        }
        //printf("%d",i);

        //on remplit le reste de la liste par des "vides" :
        while ((i-1)<5){
            strcpy(ent[i-1],"");
            i++;
        }
        printf("Jour %d. Vous avez choisi %s %s %s %s %s \n",jour,ent[0],ent[1],ent[2],ent[3],ent[4]);
        coursStockAlphabet=atof(tabCoursGoogle[jour*2-1]); //le cours du jour k est stocké dans la (k*2-1)e case du tableau tabCoursGoogle
        coursStockAmazon=atof(tabCoursAmazon[jour*2-1]);
        coursStockFacebook=atof(tabCoursFacebook[jour*2-1]);
        coursStockApple=atof(tabCoursApple[jour*2-1]);
        coursStockMicrosoft=atof(tabCoursMicrosoft[jour*2-1]);
        printf("Le cours de Google est %f, celui d'Amazon est %f, celui de Facebook est %f, celui d'Apple est %f et celui de Microsoft est %f.\n",coursStockAlphabet,coursStockAmazon,coursStockFacebook,coursStockApple,coursStockMicrosoft);
        
        //Pour chaque entreprise, on demande au joueur s'il souhaite vendre/acheter des actions
        i=0; //on initialise à la première entreprise
        

        while(strcmp(ent[i],"")!=0){  //tant qu'on est pas parvenu à la dernière entreprise choisie par le joueur
            printf("Pour %s, combien d'actions souhaitez-vous acheter ? \n",ent[i]);
            scanf("%d",&achat);
            printf("Pour %s, combien d'actions souhaitez-vous vendre ? \n",ent[i]);
            scanf("%d",&vente);


            //mettre à jour la composition du portefeuille
            fprintf(output,"Pour %s : %d actions achetées, %d action(s) vendue(s) \n",ent[i],achat,vente);


            if (strcmp(ent[i],"Amazon")==0){
                actionAmazon+=achat-vente;
                cash=cash+coursStockAmazon*(vente-achat);
                
            } else if (strcmp(ent[i],"Alphabet")==0){
                actionAlphabet+=achat-vente;
                cash=cash+coursStockAlphabet*(vente-achat);
                
            } else if (strcmp(ent[i],"Apple")==0){
                actionApple+=achat-vente;
                cash=cash+coursStockApple*(vente-achat);
            } else if (strcmp(ent[i],"Facebook")==0){
                actionFacebook+=achat-vente;
                cash=cash+coursStockFacebook*(vente-achat);
            } else if (strcmp(ent[i],"Microsoft")==0){
                actionMicrosoft+=achat-vente;
                cash=cash+coursStockMicrosoft*(vente-achat);
            }
            valeurPortefeuille=coursStockAmazon*actionAmazon + coursStockAlphabet*actionAlphabet + coursStockApple*actionApple + coursStockFacebook*actionFacebook + coursStockMicrosoft*actionMicrosoft;
            i++;
        }
        
        //à la toute fin de chaque boucle (ie pour chaque entreprise, on stocke les valeurs utiles dans le fichier
        fprintf(output,"Votre cash restant est %f. \nLa valeur de votre portefeuille est %f.\n",cash,valeurPortefeuille);
        fprintf(output,"Votre composition de portefeuille est : Alphabet %d, Amazon %d, Facebook %d, Apple %d, Microsoft %d.\n",actionAlphabet,actionAmazon,actionFacebook,actionApple,actionMicrosoft);
        
        jour++; //on passe au jour suivant
    }

    
    ROI=(valeurPortefeuille+cash-cashinitial)/cashinitial;
    fprintf(output,"Votre valeur du portefeuille est %f, votre cash est de %f, donnant un ROI de %f.\n",valeurPortefeuille,cash,ROI);
    fclose(output);


    
}