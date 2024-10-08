#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXRESERVATIONS 100

typedef struct {
    char Nom[100];
    char Prénom[100];
    char Téléphone[10];
    int Age;
    char Statut[100];
    int Référence;
    char Datederéservation[11];
} Reservation;

Reservation reservations[MAXRESERVATIONS];
int reservation_count = 0;


void initialiser_reservations() {
    const char *noms[10] = {"Amine", "Brahim", "Carime", "mohammed", "salah", "ayoub", "sliman", "Hannan", "maryam", "ilyas"};
    const char *prénoms[10] = {"bourhym", "ilidrisi", "aatya", "idtalbe", "barazize", "idblaaid", "zyach", "hakimi", "bosofa", "messi"};
    const char *téléphones[10] = {"0601010101", "0612345678", "0623456789", "0634567890", "0645678901", "0656789012", "0667890123", "0678901234", "0689012345", "0690123456"};
    int ages[10] = {30, 25, 22, 40, 35, 18, 29, 31, 33, 27};
    const char *statuts[10] = {"validé", "reporté", "validé", "annulé", "traité", "validé", "validé", "reporté", "annulé", "reporté"};
    const char *dates[10] = {"01/01/2023", "02/01/2023", "03/01/2023", "04/01/2023", "05/01/2023", "06/01/2023", "07/01/2023", "08/01/2023", "09/01/2023", "10/01/2023"};

    for (int i = 0; i < 10; i++) {
        strcpy(reservations[i].Nom, noms[i]);
        strcpy(reservations[i].Prénom, prénoms[i]);
        strcpy(reservations[i].Téléphone, téléphones[i]);
        reservations[i].Age = ages[i];
        strcpy(reservations[i].Statut, statuts[i]);
        reservations[i].Référence = i + 1;
        strcpy(reservations[i].Datederéservation, dates[i]);
    }
    reservation_count = 10;
    return;
}

void Ajouter_une_réservation() {
    if (reservation_count >= MAXRESERVATIONS) {
        printf("Impossible d'ajouter une réservation.\n");
        return;
    }

    printf("Entrez le nom: ");
    scanf("%s", reservations[reservation_count].Nom);
    printf("Entrez le prénom: ");
    scanf("%s", reservations[reservation_count].Prénom);
    printf("Entrez le téléphone: ");
    scanf("%s", reservations[reservation_count].Téléphone);
    printf("Entrez l'âge: ");
    scanf("%d", &reservations[reservation_count].Age);
    printf("Entrez le statut: ");
    scanf("%s", reservations[reservation_count].Statut);
    printf("Entrez la référence: ");
    scanf("%d", &reservations[reservation_count].Référence);
    printf("Entrez la date de réservation (format JJ/MM/AAAA): ");
    scanf("%s", reservations[reservation_count].Datederéservation);

    reservation_count++;
    printf("La réservation a été ajoutée.\n");
}

void afficher_reservations() {
    if (reservation_count == 0) {
        printf("Aucune réservation à afficher.\n");
        return;
    }

    printf("Réservations ajoutées:\n");
    for (int i = 0; i < reservation_count; i++) {
        printf("%d. Nom: %s, Prénom: %s, Âge: %d, Statut: %s, Date de réservation: %s\n",
               i + 1, reservations[i].Nom, reservations[i].Prénom, reservations[i].Age,
               reservations[i].Statut, reservations[i].Datederéservation);
    }
}
void modifier_reservation() {
    int reference;
    printf("Entrez la référence de la réservation à modifier: ");
    scanf("%d", &reference);

    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].Référence == reference) {
            printf("Modifier les informations pour la réservation %d:\n", reference);
            printf("Entrez le nouveau nom: ");
            scanf("%s", reservations[i].Nom);
            printf("Entrez le nouveau prénom: ");
            scanf("%s", reservations[i].Prénom);
            printf("Entrez le nouveau téléphone: ");
            scanf("%s", reservations[i].Téléphone);
            printf("Entrez le nouvel âge: ");
            scanf("%d", &reservations[i].Age);
            printf("Entrez le nouveau statut: ");
            scanf("%s", reservations[i].Statut);
            printf("Réservation modifiée avec succès!\n");
            return;
        }
    }
    printf("Réservation non trouvée.\n");
}

void supprimer_reservation() {
    int reference;
    printf("Entrez la référence de la réservation à supprimer: ");
    scanf("%d", &reference);

    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].Référence == reference) {
            for (int j = i; j < reservation_count - 1; j++) {
                reservations[j] = reservations[j + 1]; 
            }
            reservation_count--;
            printf("Réservation supprimée avec succès!\n");
            return;
        }
    }
    printf("Réservation non trouvée.\n");
}

void rechercher_par_reference() {
    int reference;
    printf("Entrez la référence de la réservation à rechercher: ");
    scanf("%d", &reference);

    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].Référence == reference) {
            printf("Réservation trouvée:\n");
            printf("Référence: %d, Nom: %s, Prénom: %s, Téléphone: %s, Âge: %d, Statut: %s, Date: %s\n",
                   reference, reservations[i].Nom, reservations[i].Prénom,
                   reservations[i].Téléphone, reservations[i].Age,
                   reservations[i].Statut, reservations[i].Datederéservation);
            return;
        }
    }
    printf("Réservation non trouvée.\n");
}
void afficher_statistiques() {
    if (reservation_count == 0) {
        printf("Aucune réservation pour calculer les statistiques.\n");
        return;
    }
    
    int total_age = 0;
    int age_0_18 = 0, age_19_35 = 0, age_36_plus = 0;

    for (int i = 0; i < reservation_count; i++) {
        total_age += reservations[i].Age;
        if (reservations[i].Age <= 18) age_0_18++;
        else if (reservations[i].Age <= 35) age_19_35++;
        else age_36_plus++;
    }

    double moyenne_age = (double) total_age / reservation_count;

    printf("Moyenne d'âge: %.2f\n", moyenne_age);
    printf("Nombre de patients (0-18 ans): %d\n", age_0_18);
    printf("Nombre de patients (19-35 ans): %d\n", age_19_35);
    printf("Nombre de patients (36+ ans): %d\n", age_36_plus);
}

int main() {
    int choix;

    initialiser_reservations();

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une réservation\n");
        printf("2. Modifier une réservation\n");
        printf("3. Supprimer une réservation\n");
        printf("4. Afficher les réservations\n");
        printf("5. Rechercher une réservation par référence\n");
        printf("6. Afficher les statistiques\n");
        printf("7. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajouter_une_réservation();
                break;
            case 2:
                modifier_reservation();
                break;
            case 3:
                supprimer_reservation();
                break;
            case 4:
                afficher_reservations();
                break;
            case 5:
                rechercher_par_reference(); 
                break;
            case 6:
                afficher_statistiques();
                break;
            case 7:
                printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                break;
            default:
                printf("error \n");
        }
    } while (choix != 7);

    return 0;
}
