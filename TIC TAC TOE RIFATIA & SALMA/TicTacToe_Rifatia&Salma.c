#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//TAMPILAN HOME
typedef struct{
	char line[255];
}rule;

void home(){
	int pilihan;
	FILE *isiAturan;
	rule tampilAturan[255];
	int n=0, i;

	printf("===TIC TAC TOE===\n");
	printf("\n(1)Main");
	printf("\n(2)Keluar");
	printf("\nPilihan anda : ");
	scanf("%d", &pilihan);
	
	if(pilihan == 1){
		system("cls");
		isiAturan = fopen("aturan.txt", "r+");
		while(!feof(isiAturan)) {
  			fscanf(isiAturan,"\n%[^\n]", tampilAturan[n].line);
  			n++;
		}
		for(i=0; i<n; i++){
			printf("%s\n", tampilAturan[i].line);
		}
		
		fclose(isiAturan);
		printf("click any key to continue\n");
		getch();
	}
	else if(pilihan == 2){
		exit(0);
	}
	else{
		printf("\a");	//opsional
		system("cls");
		home();
	}
}

void summary (int a, int b){
  printf("\nSummary :\n");
  printf("Nyawa : %d", a);
  printf("\ntotal skor : %d", b);
}

void option_ifwin(){
	int pilihan;

	printf("\n(1)Lanjut\n");
	printf("(2)Keluar\n");
	printf("\nCatatan : bila anda keluar maka anda harus mengulang dari easy 1");
	printf("\npilihan anda : ");
	scanf("%d", &pilihan);

	if(pilihan == 1){
		return;
	}
	else if(pilihan == 2){
		system("cls");
		home();
	}
	else{
		printf("Inputan tidak valid, mohon input ulang");
		option_ifwin();
	}
}

void option_ifKalah_Seri(){
  int pilihan;

  printf("\n(1)Mengulang ronde ini");
  printf("\n(2)Keluar\n");
  printf("\nCatatan : bila anda keluar maka anda harus mengulang dari easy 1");
  printf("\npilihan anda : ");
  scanf("%d", &pilihan);

  if(pilihan == 1){
    return;
  }
  else if(pilihan == 2){
	system("cls");
    home();
  }
  else{
    printf("Inputan tidak valid, mohon input ulang");
	option_ifKalah_Seri();
  }
}

void board_easy(char arr[3][3]){
	
	printf("  + 1 + 2 + 3 +\n");
	printf("  +---+---+---+\n");
	printf("1 | %c | %c | %c |\n", arr[0][0], arr[0][1], arr[0][2]);
	printf("  +---+---+---+\n");
	printf("2 | %c | %c | %c |\n", arr[1][0], arr[1][1], arr[1][2]);
	printf("  +---+---+---+\n");
	printf("3 | %c | %c | %c |\n",arr[2][0], arr[2][1], arr[2][2]);
	printf("  +---+---+---+\n");
}

void board_medium(char arr[5][5]){
	
	printf("  + 1 + 2 + 3 + 4 + 5 +\n");
	printf("  +---+---+---+---+---+\n");
	printf("1 | %c | %c | %c | %c | %c |\n", arr[0][0], arr[0][1], arr[0][2], arr[0][3], arr[0][4]);
	printf("  +---+---+---+---+---+\n");
	printf("2 | %c | %c | %c | %c | %c |\n", arr[1][0], arr[1][1], arr[1][2], arr[1][3], arr[1][4]);
	printf("  +---+---+---+---+---+\n");
	printf("3 | %c | %c | %c | %c | %c |\n", arr[2][0], arr[2][1], arr[2][2], arr[2][3], arr[2][4]);
	printf("  +---+---+---+---+---+\n");
	printf("4 | %c | %c | %c | %c | %c |\n", arr[3][0], arr[3][1], arr[3][2], arr[3][3], arr[3][4]);
	printf("  +---+---+---+---+---+\n");
	printf("5 | %c | %c | %c | %c | %c |\n", arr[4][0], arr[4][1], arr[4][2], arr[4][3], arr[4][4]);
	printf("  +---+---+---+---+---+\n");
}

void board_hard(char arr[7][7]){
	
	printf("  + 1 + 2 + 3 + 4 + 5 + 6 + 7 +\n");
	printf("  +---+---+---+---+---+---+---+\n");
	printf("1 | %c | %c | %c | %c | %c | %c | %c |\n", arr[0][0], arr[0][1], arr[0][2], arr[0][3], arr[0][4], arr[0][5], arr[0][6]);
	printf("  +---+---+---+---+---+---+---+\n");
	printf("2 | %c | %c | %c | %c | %c | %c | %c |\n", arr[1][0], arr[1][1], arr[1][2], arr[1][3], arr[1][4], arr[1][5], arr[1][6]);
	printf("  +---+---+---+---+---+---+---+\n");
	printf("3 | %c | %c | %c | %c | %c | %c | %c |\n", arr[2][0], arr[2][1], arr[2][2], arr[2][3], arr[2][4], arr[2][5], arr[2][6]);
	printf("  +---+---+---+---+---+---+---+\n");
	printf("4 | %c | %c | %c | %c | %c | %c | %c |\n", arr[3][0], arr[3][1], arr[3][2], arr[3][3], arr[3][4], arr[3][5], arr[3][6]);
	printf("  +---+---+---+---+---+---+---+\n");
	printf("5 | %c | %c | %c | %c | %c | %c | %c |\n", arr[4][0], arr[4][1], arr[4][2], arr[4][3], arr[4][4], arr[4][5], arr[4][6]);
	printf("  +---+---+---+---+---+---+---+\n");
	printf("6 | %c | %c | %c | %c | %c | %c | %c |\n", arr[5][0], arr[5][1], arr[5][2], arr[5][3], arr[5][4], arr[5][5], arr[5][6]);
	printf("  +---+---+---+---+---+---+---+\n");
	printf("7 | %c | %c | %c | %c | %c | %c | %c |\n", arr[6][0], arr[6][1], arr[6][2], arr[6][3], arr[6][4], arr[6][5], arr[6][6]);
	printf("  +---+---+---+---+---+---+---+\n");
}

void input_easy(char arr[3][3]){
	int baris, kolom;
	time_t start, end;
	float waktu;
	
	start = time(NULL);
	do{
		baris=0;
		printf("Pilihan koordinat baris anda : ");fflush(stdin);
		scanf("%d", &baris);
		if(baris>3||baris<1){
			printf("!! inputan tidak valid, mohon input ulang !!\n\a");
		}
	}while(baris>3||baris<1);

	do{
		kolom=0;
		printf("Pilihan koordinat kolom anda : ");
		scanf("%d", &kolom);fflush(stdin);
	}while(kolom>3||kolom<1);
	end = time(NULL);
	
	waktu = difftime(end, start);
	if(waktu<10){
		if((arr[baris-1][kolom-1] != 'X') && (arr[baris-1][kolom-1] != 'O')){
    	    arr[baris-1][kolom-1]='X';
	    }
	    else{
		    input_easy(arr);
	    }
	} 
	else{
		arr[baris-1][kolom-1]=' ';
	}
	
}

void input_medium(char arr[5][5]){
	int baris, kolom;
	time_t start, end;
	float waktu;
	
	start = time(NULL);
	do{
		baris=0;
		printf("Pilihan koordinat baris anda : ");fflush(stdin);
		scanf("%d", &baris);
		if(baris>5||baris<1){
			printf("!! inputan tidak valid, mohon input ulang !!\n\a");
		}
	}while(baris>5||baris<1);

	do{
		kolom=0;
		printf("Pilihan koordinat kolom anda : ");
		scanf("%d", &kolom);fflush(stdin);
	}while(kolom>5||kolom<1);
	end = time(NULL);
	
	waktu = difftime(end, start);
	if(waktu<10){
		if((arr[baris-1][kolom-1] != 'X') && (arr[baris-1][kolom-1] != 'O')){
    	    arr[baris-1][kolom-1]='X';
	    }
	    else{
		    input_medium(arr);
	    }
	} 
	else{
		arr[baris-1][kolom-1]=' ';
	}
	
}


void input_hard(char arr[7][7]){
	int baris, kolom;
	time_t start, end;
	float waktu;
	
	start = time(NULL);
	do{
		baris=0;
		printf("Pilihan koordinat baris anda : ");fflush(stdin);
		scanf("%d", &baris);
		if(baris>7||baris<1){
			printf("!! inputan tidak valid, mohon input ulang !!\n\a");
		}
	}while(baris>7||baris<1);

	do{
		kolom=0;
		printf("Pilihan koordinat kolom anda : ");
		scanf("%d", &kolom);fflush(stdin);
	}while(kolom>7||kolom<1);
	end = time(NULL);
	
	waktu = difftime(end, start);
	if(waktu<10){
		if((arr[baris-1][kolom-1] != 'X') && (arr[baris-1][kolom-1] != 'O')){
    	    arr[baris-1][kolom-1]='X';
	    }
	    else{
		    input_hard(arr);
	    }
	} 
	else{
		arr[baris-1][kolom-1]=' ';
	}
	
}

int check_easy(char arr[3][3]){

	int baris, kolom;

	// cek horizontal
	for(baris = 0; baris < 3; baris++){
		if((arr[baris][0] == arr[baris][1]) && (arr[baris][1] == arr[baris][2])){
			if(arr[baris][0] == 'X'){
				return -1;	//asalnya 10 (diganti : 12 feb 21)
			}
			else if (arr[baris][0] == 'O'){
				return 1;	//asalnya -10 (diganti : 12 feb 21)
			}
		}
	}

	//cek vertikal
	for(kolom = 0; kolom < 3; kolom++){
		if((arr[0][kolom] == arr[1][kolom]) && (arr[1][kolom] == arr[2][kolom])){
			if(arr[0][kolom] == 'X'){
				return -1;		//asalnya 10 (diganti : 12 feb 21)
			}
			else if (arr[0][kolom] == 'O'){
				return 1;		//asalnya -10 (diganti : 12 feb 21)
			}
		}
	}

	//cek diagonal
	if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])){
		if(arr[0][0] == 'X'){
			return -1;
		}
		else if (arr[0][0] == 'O'){
			return 1;	
		}
	}
	if((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0])){
		if(arr[0][2] == 'X'){
			return -1;	
		}
		else if (arr[0][2] == 'O'){
			return 1;	
		}
	}
	
	return 0;
	
}

void cek_win(int a){
	if(a == -1){
		printf("\nAnda menang!");getch();
	}
	if(a == 1){
		printf("\nAnda kalah!");getch();
	}
	if(a == 2){
		printf("\nSeri");getch();
	}
}

int minimax(char board[3][3], int player) {
	//Tic-tac-toe playing AI. Exhaustive tree-search. WTFPL
	//Matthew Steel 2009, www.www.repsilat.com
	//dengan penyesuaian
	
    //How is the position like for player (their turn) on board?
    int winner = check_easy(board);
    if(winner != 0) return winner*player;

    int moveBaris = -1;
    int moveKolom = -1;
    int skor = -2;//Losing moves are preferred to no move
    int i,j;
    int limit = 2;
    for(i = 0; i < 3; i++){//For all moves, 
        for(j = 0; j<3; j++){
        	if((board[i][j] != 'X') && (board[i][j] != 'O')){//If legal, //if(board[i][j] == ' ')
				if(player == -1){
					board[i][j] = 'X';//Try the move	
				}
				else if(player == 1){
					board[i][j] = 'O';//Try the move
				}
            	int thisScore = -minimax(board, player*-1);
            	if(thisScore > skor) {
                	skor = thisScore; 
                	moveBaris = i;
                	moveKolom = j;
            	}//Pick the one that's worst for the opponent
            	board[i][j] = ' ';//Reset board after try
            	limit--;
			}
			if(limit<=0){
				break;
			}
        }
        if(limit<=0){
			break;
		}
    }
    if((moveBaris == -1) && (moveKolom == -1))return 0;
    return skor;
}

void computerMove_easy(char board[3][3]){
	//Tic-tac-toe playing AI. Exhaustive tree-search. WTFPL
	//Matthew Steel 2009, www.www.repsilat.com
	//dengan penyesuaian
	
    int moveBaris = -1;
    int moveKolom = -1;
    int skor = -2;
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j=0; j<3; j++){
        	if((board[i][j] != 'X') && (board[i][j] != 'O')) {	//if(board[i][j] == ' ')
            	board[i][j] = 'O';
            	int tempScore = -minimax(board, -1);
            	board[i][j] = ' ';
            	if(tempScore > skor) {
                	skor = tempScore;
                	moveBaris = i;
                	moveKolom = j;
    			}
			}
        }
    }
    //returns a score based on minimax tree at a given node.
    board[moveBaris][moveKolom] = 'O';
}

int checkfull_easy(char arr[3][3]){
	int baris, kolom;
	int terisi = 0;
	
	for(baris=0; baris<3; baris++){
		for(kolom=0; kolom<3; kolom++){
			if((arr[baris][kolom] == 'X') || (arr[baris][kolom] == 'O')){
				terisi++;
			}
		}
	}
	
	if (terisi == 9){
		return 2;
	}
	
	return 0;
	
}

void clearBoard_easy(char arr[3][3]){
	int baris, kolom;
	for(baris=0; baris<3; baris++){
		for(kolom=0; kolom<3; kolom++){
			arr[baris][kolom] = ' ';
		}
	}
}

void countNyawa_Skor(int winner, int *skor, int *live){
	if(winner == -1){
		*skor = *skor + 10;
	}
	if(winner == 1){
		*live = *live - 1;
		*skor = *skor - 6;
	}
	if(winner == 2){
		*live = *live - 1;
		*skor = *skor - 3;	
	}
}

void random_easy(char arr[3][3]){
	int baris, kolom;

	baris = rand()%3;
	kolom = rand()%3;

	if((arr[baris][kolom] != 'X') && (arr[baris][kolom] != 'O')){
		printf("Pilihan kotak anda diacak dengan koordinat baris %d dan kolom %d", baris+1, kolom+1);
    	arr[baris][kolom]='X';
	}
	else{
		random_easy(arr);
	}
}

void tampilan_Easy(int *ronde, int *nyawa, int *score, char arr[3][3]){
	time_t start, end;
	float waktu;
	int baris, kolom, terisi;
	terisi=0;
	int winner;
	int tahap = *ronde;
	int skor = *score;
	int live = *nyawa;
	system("cls");
	
	winner = check_easy(arr);
	if(winner == 0){
		winner = checkfull_easy(arr);
	}
	countNyawa_Skor(winner, &skor, &live);
	
	printf("===TIC TAC TOE===\n\n");
	printf("Easy %d\n", tahap);
	printf("Nyawa : %d\n", live);
	printf("Current score : %d\n", skor);
	board_easy(arr);
	printf("\n");
	
	
	cek_win(winner);
	if(winner == -1){
		tahap++;
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_easy(arr);
		summary(*nyawa, *score);
		option_ifwin();
		return;
	}
	if(winner == 1){
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_easy(arr);
		summary(*nyawa, *score);
		option_ifKalah_Seri();
		return;
	}
	if(winner == 2){
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_easy(arr);
		summary(*nyawa, *score);
		option_ifKalah_Seri();
		return;
	}
	
	if (winner == 0){
		start = time (NULL);
		input_easy(arr);
		end = time (NULL);
	}
	
	waktu = difftime(end, start);
	if (waktu > 10){
		random_easy(arr);
		printf("\nTime taken to input symbol is %.2f seconds", waktu);getch();
	}
	else if (waktu < 5){
		skor = skor + 2;
	}
	else{
		skor = skor + 1;
	}

	winner = check_easy(arr);
	if(winner == 0){
		computerMove_easy(arr);
	}
	
	*ronde = tahap;
	*score = skor;
	*nyawa = live;
}

int checkfull_medium(char arr[5][5]){
	int baris, kolom;
	int terisi = 0;
	
	for(baris=0; baris<5; baris++){
		for(kolom=0; kolom<5; kolom++){
			if((arr[baris][kolom] == 'X') || (arr[baris][kolom] == 'O')){
				terisi++;
			}
		}
	}
	
	if (terisi == 25){
		return 2;
	}
	
	return 0;
}

void random_medium(char arr[5][5]){
	int baris, kolom;

	baris = rand()%5;
	kolom = rand()%5;

	if((arr[baris][kolom] != 'X') && (arr[baris][kolom] != 'O')){
		printf("Pilihan kotak anda diacak dengan koordinat baris %d dan kolom %d", baris+1, kolom+1);
    	arr[baris][kolom]='X';
	}
	else{
		random_medium(arr);
	}
}

int check_medium(char arr[5][5]){
	int baris, kolom;

	// cek horizontal
	for(baris = 0; baris < 5; baris++){
		if((arr[baris][0] == arr[baris][1]) && (arr[baris][1] == arr[baris][2]) && (arr[baris][2] == arr[baris][3]) && (arr[baris][3] == arr[baris][4])){
			if(arr[baris][0] == 'X'){
				return -1;
			}
			else if (arr[baris][0] == 'O'){
				return 1;
			}
		}
	}

	//cek vertikal
	for(kolom = 0; kolom < 5; kolom++){
		if((arr[0][kolom] == arr[1][kolom]) && (arr[1][kolom] == arr[2][kolom]) && (arr[2][kolom] == arr[3][kolom]) && (arr[3][kolom] == arr[4][kolom])){
			if(arr[0][kolom] == 'X'){
				return -1;
			}
			else if (arr[0][kolom] == 'O'){
				return 1;
			}
		}
	}

	//cek diagonal
	if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && (arr[2][2] == arr[3][3]) && (arr[3][3] == arr[4][4])){
		if(arr[0][0] == 'X'){
			return -1;
		}
		else if (arr[0][0] == 'O'){
			return 1;
		}
	}
	if((arr[0][4] == arr[1][3]) && (arr[1][3] == arr[2][2]) && (arr[2][2] == arr[3][1]) && (arr[3][1] == arr[4][0])){
		if(arr[0][4] == 'X'){
			return -1;
		}
		else if (arr[0][4] == 'O'){
			return 1;
		}
	}

	return 0;

}

void clearBoard_medium(char arr[5][5]){
	int baris, kolom;
	for(baris=0; baris<5; baris++){
		for(kolom=0; kolom<5; kolom++){
			arr[baris][kolom] = ' ';
		}
	}
}

int minimax_medium(char board[5][5], int player) {
	//Tic-tac-toe playing AI. Exhaustive tree-search. WTFPL
	//Matthew Steel 2009, www.www.repsilat.com
	//dengan penyesuaian
	
    //How is the position like for player (their turn) on board?
    int winner = check_medium(board);
    if(winner != 0) return winner*player;

    int moveBaris = -1;
    int moveKolom = -1;
    int skor = -2;//Losing moves are preferred to no move
    int i,j;
    int limit = 2;
    for(i = 0; i<5; i++){//For all moves, 
        for(j = 0; j<5; j++){
        	if((board[i][j] != 'X') && (board[i][j] != 'O')){//If legal, //if(board[i][j] == ' ')
				if(player == -1){
					board[i][j] = 'X';//Try the move	
				}
				else if(player == 1){
					board[i][j] = 'O';//Try the move
				}
            	int thisScore = -minimax_medium(board, player*-1);
            	if(thisScore > skor) {
                	skor = thisScore; 
                	moveBaris = i;
                	moveKolom = j;
            	}//Pick the one that's worst for the opponent
            	board[i][j] = ' ';//Reset board after try
            	limit--;
			}
			if(limit<=0){
				break;
			}
        }
        if(limit<=0){
			break;
		}
    }
    if((moveBaris == -1) && (moveKolom == -1))return 0;
    return skor;
}

void computerMove_medium(char board[5][5]){
	//Tic-tac-toe playing AI. Exhaustive tree-search. WTFPL
	//Matthew Steel 2009, www.www.repsilat.com
	//dengan penyesuaian
	
    int moveBaris = -1;
    int moveKolom = -1;
    int skor = -2;
    int i, j;
    for(i=0; i<5 ; i++) {
        for(j=0; j<5 ; j++){
        	if((board[i][j] != 'X') && (board[i][j] != 'O')) {
            	board[i][j] = 'O';
            	int tempScore = -minimax_medium(board, -1);
            	board[i][j] = ' ';
            	if(tempScore > skor) {
                	skor = tempScore;
                	moveBaris = i;
                	moveKolom = j;
    			}
			}
        }
    }
    //returns a score based on minimax tree at a given node.
    board[moveBaris][moveKolom] = 'O';
}

void tampilan_Medium(int *ronde, int *nyawa, int *score, char arr[5][5]){
	time_t start, end;
	float waktu;
	int baris, kolom, terisi;
	terisi=0;
	int winner;
	int tahap = *ronde;
	int skor = *score;
	int live = *nyawa;
	system("cls");
	
	winner = check_medium(arr);
	if(winner == 0){
		winner = checkfull_medium(arr);
	}
	countNyawa_Skor(winner, &skor, &live);
	
	printf("===TIC TAC TOE===\n\n");
	printf("Medium %d\n", tahap);
	printf("Nyawa : %d\n", live);
	printf("Current score : %d\n", skor);
	board_medium(arr);
	printf("\n");
	
	
	cek_win(winner);
	if(winner == -1){
		tahap++;
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_medium(arr);
		summary(*nyawa, *score);
		option_ifwin();
		return;
	}
	if(winner == 1){
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_medium(arr);
		summary(*nyawa, *score);
		option_ifKalah_Seri();
		return;
	}
	if(winner == 2){
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_medium(arr);
		summary(*nyawa, *score);
		option_ifKalah_Seri();
		return;	
	}
	
	if (winner == 0){
		start = time (NULL);
		input_medium(arr);
		end = time (NULL);
	}
	
	waktu = difftime(end, start);
	if (waktu > 10){
		random_medium(arr);
		printf("\nTime taken to input symbol is %.2f seconds", waktu);getch();
	}
	else if (waktu < 5){
		skor = skor + 2;
	}
	else{
		skor = skor + 1;
	}

	winner = check_medium(arr);
	if(winner == 0){
		computerMove_medium(arr);
	}
	
	*ronde = tahap;
	*score = skor;
	*nyawa = live;
	
}

int check_hard(char arr[7][7]){
	int baris, kolom;

	// cek horizontal
	for(baris = 0; baris < 7; baris++){
		if((arr[baris][0] == arr[baris][1]) && (arr[baris][1] == arr[baris][2]) && (arr[baris][2] == arr[baris][3]) && (arr[baris][3] == arr[baris][4]) && (arr[baris][4] == arr[baris][5]) && (arr[baris][5] == arr[baris][6])){
			if(arr[baris][0] == 'X'){
				return -1;
			}
			else if (arr[baris][0] == 'O'){
				return 1;
			}
		}
	}

	//cek vertikal
	for(kolom = 0; kolom < 3; kolom++){
		if((arr[0][kolom] == arr[1][kolom]) && (arr[1][kolom] == arr[2][kolom]) && (arr[2][kolom] == arr[3][kolom]) && (arr[3][kolom] == arr[4][kolom]) && (arr[4][kolom] == arr[5][kolom]) && (arr[5][kolom] == arr[6][kolom])){
			if(arr[0][kolom] == 'X'){
				return -1;
			}
			else if (arr[0][kolom] == 'O'){
				return 1;
			}
		}
	}

	//cek diagonal
	if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && (arr[2][2] == arr[3][3]) && (arr[3][3] == arr[4][4]) && (arr[4][4] == arr[5][5]) && (arr[5][5] == arr[6][6])){
		if(arr[0][0] == 'X'){
			return -1;
		}
		else if (arr[0][0] == 'O'){
			return 1;
		}
	}
	if((arr[0][6] == arr[1][5]) && (arr[1][5] == arr[2][4]) && (arr[2][4] == arr[3][3]) && (arr[3][3] == arr[4][2]) && (arr[4][2] == arr[5][1]) && (arr[5][1] == arr[6][0])){
		if(arr[0][6] == 'X'){
			return -1;
		}
		else if (arr[0][6] == 'O'){
			return 1;
		}
	}
	
	return 0;

}

int checkfull_hard(char arr[7][7]){
	int baris, kolom;
	int terisi = 0;
	
	for(baris=0; baris<7; baris++){
		for(kolom=0; kolom<7; kolom++){
			if((arr[baris][kolom] == 'X') || (arr[baris][kolom] == 'O')){
				terisi++;
			}
		}
	}
	
	if (terisi == 49){
		return 2;
	}
	
	return 0;
	
}

void clearBoard_hard(char arr[7][7]){
	int baris, kolom;
	for(baris=0; baris<7; baris++){
		for(kolom=0; kolom<7; kolom++){
			arr[baris][kolom] = ' ';
		}
	}
}


void randomComputer_hard(char arr[7][7]){
	int baris, kolom;

	baris = rand()%7;
	kolom = rand()%7;

	if((arr[baris][kolom] != 'X') && (arr[baris][kolom] != 'O')){
    	arr[baris][kolom]='O';
	}
	else{
		randomComputer_hard(arr);
	}
}

void random_hard(char arr[7][7]){
	int baris, kolom;

	baris = rand()%7;
	kolom = rand()%7;

	if((arr[baris][kolom] != 'X') && (arr[baris][kolom] != 'O')){
		printf("Pilihan kotak anda diacak dengan koordinat baris %d dan kolom %d", baris+1, kolom+1);
    	arr[baris][kolom]='X';
	}
	else{
		random_hard(arr);
	}
}



void tampilan_Hard(int *ronde, int *nyawa, int *score, char arr[7][7]){
	time_t start, end;
	float waktu;
	int baris, kolom, terisi;
	terisi=0;
	int winner;
	int tahap = *ronde;
	int skor = *score;
	int live = *nyawa;
	system("cls");
	
	winner = check_hard(arr);
	if(winner == 0){
		winner = checkfull_hard(arr);
	}
	countNyawa_Skor(winner, &skor, &live);
	
	printf("===TIC TAC TOE===\n\n");
	printf("Hard %d\n", tahap);
	printf("Nyawa : %d\n", live);
	printf("Current score : %d\n", skor);
	board_hard(arr);
	printf("\n");
	
	
	cek_win(winner);
	if(winner == -1){
		tahap++;
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_hard(arr);
		summary(*nyawa, *score);
		option_ifwin();
		return;
	}
	if(winner == 1){
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_hard(arr);
		summary(*nyawa, *score);
		option_ifKalah_Seri();
		return;
	}
	if(winner == 2){
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		clearBoard_hard(arr);
		summary(*nyawa, *score);
		option_ifKalah_Seri();
		return;
	}
	
	if (winner == 0){
		start = time (NULL);
		input_hard(arr);
	}
	
	waktu = difftime(end, start);
	if (waktu > 10){
		random_hard(arr);
		printf("\nTime taken to input symbol is %.2f seconds", waktu);getch();
	}
	else if (waktu < 5){
		skor = skor + 2;
	}
	else{
		skor = skor + 1;
	}
	
	winner = check_hard(arr);
	if(winner == 0){
		randomComputer_hard(arr);
	}
	
	*ronde = tahap;
	*score = skor;
	*nyawa = live;
}

void main(){
	char isi_easy[3][3]={};
	char isi_medium[5][5]={};
	char isi_hard[7][7]={{},{},{},{},{},{' ', ' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' ', ' '}};
	int pilihan;
	int nyawa=3;
	int score=10;
	int ronde=1;
	int baris, kolom;
	
	home();
	
	//memulai dari level easy (bidak ukuran 3x3)
	while((ronde<4)&&(nyawa>0)&&(score>0)){
		tampilan_Easy(&ronde, &nyawa, &score, isi_easy);
	}	
	
	
	//melanjut ke level medium (bidak ukuran 5x5) jika masih memiliki nyawa
	if(nyawa>0){
		ronde = 1;
		summary(nyawa, score);
	}
	while((ronde<4)&&(nyawa>0)&&(score>0)){
		tampilan_Medium(&ronde, &nyawa, &score, isi_medium);
	}
	
	
	//melanjut ke level hard (bidak ukuran 7x7) jika masih memiliki nyawa
	if(nyawa>0){
		ronde = 1;
		summary(nyawa, score);
	}
	while((ronde<4)&&(nyawa>0)&&(score>0)){
		tampilan_Hard(&ronde, &nyawa, &score, isi_hard);
	}
}
