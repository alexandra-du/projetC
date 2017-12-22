#include <stdio.h>
#include <string.h>

int main(){
    char nom[30],ch;
    char entreprise[10]; 
    int cash,vente,achat;
    float actionApple,actionAmazon,actionAlphabet,actionFacebook,actionMicrosoft;
    actionApple=actionAmazon=actionAlphabet=actionFacebook=actionMicrosoft=0;
    int jour, i; //jour = numéro du jour de novembre
    char ent[5][10]; //ent sera la liste d'entreprises qui intéressent le joueur. Elle peut contenir au maximum 5 entreprises (Amazon, Google, etc) de 10 caractères
    float coursStock=0,valeurPortefeuille;
    float cash,ROI;

    char filename[20];
    FILE *output;
    printf("Veuillez choisir un nom de fichier. \n");
    scanf("%s",filename);
    output=fopen(filename,"w");
    

    printf("Veuillez indiquer le nom du joueur. \n");
    scanf("%s",nom);
    fprintf(output,"Résultats du joueur %s \n",nom);
    printf("Veuillez indiquer le montant initial dont vous disposez. \n");
    scanf("%d",&cash);
    

    jour=1; // on commence le 1er novembre
    while(jour<=30){ //tant qu'on est avant le 30/11
        //on exclut les weekends de novembre qui sont les 4/11 et 5/11 etc
        while (jour%7==4 ||jour%7==5){
            jour++;
        } 
        
        printf("Jour %d. \nPour rappel, votre composition actuelle de portefeuille est : Alphabet %f, Amazon %f, Facebook %f, Apple %f, Microsoft %f.\n Vous disposez de %f. \n",jour,actionAlphabet,actionAmazon,actionFacebook,actionApple,actionMicrosoft,cash);
        fprintf(output,"Résultats du jour %d :\n\n",jour);
            
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
        
        //Pour chaque action, on demande au joueur s'il souhaite vendre/acheter des actions
        i=0; //on initialise à la première entreprise
        while(strcmp(ent[i],"")!=0){  //tant qu'on est pas parvenu à la dernière entreprise choisie par le joueur
            printf("Pour %s, combien d'actions souhaitez-vous acheter ? \n",ent[i]);
            scanf("%d",&achat);
            printf("Pour %s, combien d'actions souhaitez-vous vendre ? \n",ent[i]);
            scanf("%d",&vente);
            
            //cash=cash + ou - blabla
            //mettre à jour la composition du portefeuille
            fprintf(output,"Pour %s : %d actions achetées, %d action(s) vendue(s) \n",ent[i],achat,vente);
            fprintf(output,"blabla les valeurs du jour i et de l'entreprise x à stocker \n");
            
            if (strcmp(ent[i],"Amazon")==0){
                coursStockAmazon= 9;
                actionAmazon+=achat-vente;
                valeurPortefeuille+=coursStockAmazon*actionAmazon;
                cash=cash+coursStockAmazon*(vente-achat);
                
            } else if (strcmp(ent[i],"Alphabet")==0){
                actionAlphabet+=achat-vente;
                valeurPortefeuille+=coursStock*actionAlphabet;
                fprintf(output,"Le cours pour Alphabet est %f. Vous détenez %d actions d'Alphabet.\n",coursStock,actionAlphabet);
            } else if (strcmp(ent[i],"Apple")==0){
                actionApple+=achat-vente;
                valeurPortefeuille+=coursStock*actionApple;
                fprintf(output,"Le cours pour Apple est %f. Vous détenez %d actions d'Apple.\n",coursStock,actionApple);
            } else if (strcmp(ent[i],"Facebook")==0){
                actionFacebook+=achat-vente;
                valeurPortefeuille+=coursStock*actionFacebook;
                fprintf(output,"Le cours pour Facebook est %f. Vous détenez %d actions de Facebook.\n",coursStock,actionFacebook);
            } else if (strcmp(ent[i],"Microsoft")==0){
                actionMicrosoft+=achat-vente;
                valeurPortefeuille+=coursStock*actionMicrosoft;
                fprintf(output,"Le cours pour Microsoft est %f. Vous détenez %d actions de Microsoft.\n",coursStock,actionMicrosoft);
            }
            
            i=i+1;
        }
        
        //à la toute fin de chaque boucle (ie pour chaque entreprise, on stocke les valeurs utiles dans le fichier
        
        fprintf(output,"Votre cash restant est %f. \nLa valeur de votre portefeuille est %f.\n",cash,valeurPortefeuille);
        fprintf(output,"Votre composition de portefeuille est : Alphabet %f, Amazon %f, Facebook %f, Apple %f, Microsoft %f.\n",actionAlphabet,actionAmazon,actionFacebook,actionApple,actionMicrosoft);
        
        jour++; //on passe au jour suivant
    }

    //fprintf(output,"blabla Résultats finaux, ROI\n");
    //ROI=
    fclose(output);
    //printf("%s %s %s %s %s \n",ent[0],ent[1],ent[2],ent[3],ent[4]);

    
}
