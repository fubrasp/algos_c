// on notera des ameliorations possibles au niveau naming m, n n index ligne colonne etc
// ameliorations possible sur par exemple l'utilisation de define
//principe je lis en haut a gauche vers le bas en i, j en dessinant dans ma tete des carres virtuels
void computeS(int m, int n) {

    //cas limite, 1 seule case en haut a gauche, bas besoin de lancer un tambouille de boucles etc dans ce cas
    if(M[0][0] == 0) {
        S[0][0] = 1;
    }



    //****les bordures
    //on traite un cas limite la premiere ligne visibelement j aurait ete plus judicieux comme nom par l'usage
    for (int i = 1; i < n; i++) {
        if(M[0][i] == 0) {
            S[0][i] = S[0][i - 1] + 1;
        } else{
            S[0][i] = S[0][i - 1];
        }
    }

    for (int i = 1; i < m; i++) {
        if (M[i][0] == 0) {
            S[i][0] = S[i - 1][0] + 1;
        } else {
            S[i][0] = S[i - 1][0];
        }
    }
    //les bordures****


    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (M[i][j] == 0) {
                S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + 1;
            } else {
                S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
            }
        }
    }
}