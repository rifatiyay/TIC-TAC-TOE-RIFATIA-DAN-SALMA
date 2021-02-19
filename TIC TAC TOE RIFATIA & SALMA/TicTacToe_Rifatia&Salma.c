#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//TAMPILAN HOME
typedef struct{
	char line[255];
}rule;

void home(){
	/* 
	PIC/Author : ver 1 : Salma , ver 2 : Rifatia
	Deskripsi : Menampilkan halaman utama yang terdiri dari opsi main dan keluar.
	IS : Layar kosong
	FS : Layar menjadi tampilan home
	*/
	
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
		printf("\nclick any key to continue\n");
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : menampilkan kesimpulan jumlah nyawa dan score
	IS : kesimpulan jumlah skor dan nyawa belum ditampilkan
	FS : kesimpulan jumlah skor dan nyawa ditampilkan
	*/

	printf("\nSummary :\n");
	printf("Nyawa : %d", a);
	printf("\ntotal skor : %d", b);
}

void showHighscore(int skor){
	/* 
	PIC/Author : Salma Syawalan P
	Deskripsi : menyimpan ke file dan menampilkan skor tertinggi yang diraih pemain
	IS : skor tertinggi yang diraih pemain tidak tersimpan dalam file dan tidak ditampilkan
	FS : skor tertinggi yang diraih pemain tidak tersimpan dalam file dan tidak ditampilkan
	*/
	
	FILE *fp;
	int highscore;
	
	fp = fopen("highscore.txt", "r+");
	highscore = getw(fp);
	fclose(fp);
	
	fp = fopen("highscore.txt", "r+");
	if(skor > highscore){
		printf("\n\nNEW HIGHSCORE!\nhighscore : %d", skor);
		putw(skor, fp);
	}
	else{
		printf("\nhighscore : %d", highscore);
	}
	fclose(fp);
	
}

void option_ifKalah_Seri(int *nyawa, int skor){
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : menampilkan tampilan saat player kalah
	IS : tidak muncul pilihan melanjutkan game
	FS : muncul pilihan melanjutkan game
	*/
	
	int pilihan;
	int a = *nyawa;

	printf("\n(1)Mengulang ronde ini");
	printf("\n(2)Keluar\n");
	printf("\nCatatan : bila anda keluar maka anda harus mengulang dari easy 1");
	printf("\npilihan anda : ");
	scanf("%d", &pilihan);

	if(pilihan == 1){
		return;
	}
	else if(pilihan == 2){
		showHighscore(skor);
		printf("\nclick any key to continue");getch();
		a = 0;
		*nyawa = a;
		system("cls");
    	home();
  }
  else{
    printf("Inputan tidak valid, mohon input ulang");
	option_ifKalah_Seri(&a, skor);
  }
}

void option_ifwin(int *nyawa, int skor){
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : menampilkan tampilan saat player menang
	IS : tidak muncul pilihan melanjutkan game bagi pemenang
	FS : muncul pilihan melanjutkan game bagi pemenang
	*/
	
	int pilihan;
	int a = *nyawa;

	printf("\n(1)Lanjut\n");
	printf("(2)Keluar\n");
	printf("\nCatatan : bila anda keluar maka anda harus mengulang dari easy 1");
	printf("\npilihan anda : ");
	scanf("%d", &pilihan);

	if(pilihan == 1){
		return;
	}
	else if(pilihan == 2){
		showHighscore(skor);
		printf("\nclick any key to continue");getch();
		a = 0;
		*nyawa = a;
		system("cls");
		home();
	}
	else{
		printf("Inputan tidak valid, mohon input ulang");
		option_ifwin(&a, skor);
	}
}

void ifGameOver(int a, int b){
	/* 
	PIC/Author : 
	Deskripsi : 
	IS : 
	FS : 
	*/
	
	printf("\n\n###  GAME OVER  ###");
	summary(a,b);
	showHighscore(b);
	/*if(b > data.highscore){  //ini gatau gmn kan file
	    //pseudocode campur2
	    data.highscore <-- b
	    printf("!! NEW HIGHSCORE !!");
	    printf("highscore = %d", b);
	    write(file data)data.highscore
  	}
  	else if(b <= data.highscore){
    	printf("highscore = %d", data.highscore);
  	}*/
	printf("\n\nclick any button to continue to home page");getch();
	system("cls");
	home();

}

void ifVictory(int a, int b){
	/* 
	PIC/Author :
	Deskripsi : 
	IS : 
	FS : 
	*/
	
	printf("\n>= V I C T O R Y =<");
	summary(a, b);
	showHighscore(b);
	printf("\n\nclick any button to continue to home page");getch();
	system("cls");
	home();

}

void board_easy(char arr[3][3]){
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : Membuat tampilan papan permainan berukuran 3x3
	IS : tidak ada tampilan papan pada layar
	FS : muncul tampilan papan berukuran 3x3 pada layar
	*/
	
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
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : Membuat tampilan papan permainan berukuran 5x5
	IS : tidak ada tampilan papan pada layar
	FS : muncul tampilan papan berukuran 5x5 pada layar
	*/
	
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
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : Membuat tampilan papan permainan berukuran 7x7
	IS : tidak ada tampilan papan pada layar
	FS : muncul tampilan papan berukuran 7x7 pada layar
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan p.
	Deskripsi : untuk menginputkan pilihan kotak berukuran 3x3 yang kosong oleh player.
	IS : array 3x3 masih kosong
	FS : array 3x3 terisi oleh simbol X
	*/
	
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
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : untuk menginputkan pilihan kotak berukuran 5x5 yang kosong oleh player.
	IS : array 5x5 masih kosong
	FS : array 5x5 terisi oleh simbol X
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : untuk menginputkan pilihan kotak berukuran 7x7 yang kosong oleh player.
	IS : array 7x7 masih kosong
	FS : array 7x7 terisi oleh simbol X
	*/
	
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

int checkWin_easy(char arr[3][3]){
	/* 
	PIC/Author : Salma Syawalan P
	Deskripsi : mengecek apakah sudah ada simbol yang membentuk pola di papan permainan ukuran 3x3
	*/

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

void show_WinOrLose(int a){
	/* 
	PIC/Author : Salma Syawalan P. 
	Deskripsi : Menentukan siapakah pemenang dari game tic tac toe berdasarkan nilai return dari modul check_easy, check_medium, atau check_hard.
	IS : belum ditampilkan keterangan apakah player berada dalam kondisi menang, kalah, atau serinya
	FS : muncul tampilan yang menyatakan menang, kalah atau seri.
	*/
	
	if(a == -1){
		printf("\nAnda menang!");
	}
	if(a == 1){
		printf("\nAnda kalah!");
	}
	if(a == 2){
		printf("\nSeri");
	}
}

int minimax_easy(char board[3][3], int player) {
	/* 
	PIC/Author : Salma Syawalan
	Deskripsi : mencari langkah yang memungkinkan untuk komputer di papan permainan berukuran 3x3
	*/
	
	//Tic-tac-toe playing AI. Exhaustive tree-search. WTFPL
	//Matthew Steel 2009, www.www.repsilat.com
	//dengan penyesuaian
	
    //How is the position like for player (their turn) on board?
    int winner = checkWin_easy(board);
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
            	int thisScore = -minimax_easy(board, player*-1);
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : menentukan langkah yang akan diambil komputer di papan permainan berukuran 3x3
	IS : salah satu kotak pada papan 3x3 kosong
	FS : salah satu kotak pada papan 3x3 sudah terisi oleh simbol O
	*/
	
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
            	int tempScore = -minimax_easy(board, -1);
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
	/* 
	PIC/Author : Salma Syawalan P. 
	Deskripsi : mengecek apakah papan permainan berukuran 3x3 sudah terisi penuh atau tidak.
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : untuk mengosongkan seluruh isi kotak pada papan permainan 3x3.
	IS : kotak pada papan 3x3 terisi simbol
	FS : kotak pada papan 3x3 sudah kosong
	*/
	
	int baris, kolom;
	for(baris=0; baris<3; baris++){
		for(kolom=0; kolom<3; kolom++){
			arr[baris][kolom] = ' ';
		}
	}
}

void countNyawa_Skor(int winner, int *skor, int *live){
	/* 
	PIC/Author : Rifatia Yumna Salma.
	Deskripsi : menghitung jumlah nyawa milik player yang tersisa.
	IS : jumlah nyawa player terbilang
	FS : jumlah nyawa player menjadi tetap atau berkurang
	*/
	
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
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : mengacak kotak pada papan 3x3 yang akan diisi simbol milik player saat player menginput lebih dari 10 detik
	IS : suatu kotak belum terisi oleh simbol
	FS : suatu kota terisi oleh simbol X secara acak
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : menampilkan tampilan game pada level easy.
	IS : program tidak menampilkan apapun
	FS : program menampilkan tampilan game level easy.
	*/
	
	time_t start, end;
	float waktu;
	int baris, kolom, terisi;
	terisi=0;
	int winner;
	int tahap = *ronde;
	int skor = *score;
	int live = *nyawa;
	system("cls");
	
	winner = checkWin_easy(arr);
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
	
	
	show_WinOrLose(winner);
	if(winner == -1){
		tahap++;
		clearBoard_easy(arr);
		summary(live, skor);
		option_ifwin(&live, skor);
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		return;
	}
	if((winner == 1) || (winner == 2)) {
		clearBoard_easy(arr);
		if (live > 0){
			summary(live, skor);
			option_ifKalah_Seri(&live, skor);
		} 
		else{
			ifGameOver(live, skor);
		}
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
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

	winner = checkWin_easy(arr);
	if(winner == 0){
		computerMove_easy(arr);
	}
	
	*ronde = tahap;
	*score = skor;
	*nyawa = live;
}

int checkfull_medium(char arr[5][5]){
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : mengecek apakah papan permainan berukuran 5x5 sudah terisi penuh atau tidak.
	*/
	
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
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : mengacak kotak pada papan 5x5 yang akan diisi simbol milik player saat player menginput lebih dari 10 detik
	IS : suatu kotak belum terisi oleh simbol
	FS : suatu kota terisi oleh simbol X secara acak
	*/
	
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

int checkWin_medium(char arr[5][5]){
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : mengecek apakah sudah ada simbol yang membentuk pola di papan permainan ukuran 5x5
	*/
	
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
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : untuk mengosongkan seluruh isi kotak pada papan permainan 5x5.
	IS : kotak pada papan 5x5 terisi simbol
	FS : kotak pada papan 5x5 sudah kosong
	*/
	
	int baris, kolom;
	for(baris=0; baris<5; baris++){
		for(kolom=0; kolom<5; kolom++){
			arr[baris][kolom] = ' ';
		}
	}
}

int minimax_medium(char board[5][5], int player) {
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : mencari langkah yang memungkinkan untuk komputer di papan permainan berukuran 5x5
	*/
	
	//Tic-tac-toe playing AI. Exhaustive tree-search. WTFPL
	//Matthew Steel 2009, www.www.repsilat.com
	//dengan penyesuaian
	
    //How is the position like for player (their turn) on board?
    int winner = checkWin_medium(board);
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
	/* 
	PIC/Author : Rifatia Yumna Salma.
	Deskripsi : menentukan langkah yang akan diambil komputer di papan permainan berukuran 5x5
	IS : salah satu kotak pada papan 5x5 kosong
	FS : salah satu kotak pada papan 5x5 sudah terisi oleh simbol O
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : menampilkan tampilan game pada level medium
	IS : program tidak menampilkan apapun
	FS : program menampilkan tampilan game level medium.
	*/
	
	time_t start, end;
	float waktu;
	int baris, kolom, terisi;
	terisi=0;
	int winner;
	int tahap = *ronde;
	int skor = *score;
	int live = *nyawa;
	system("cls");
	
	winner = checkWin_medium(arr);
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
	
	
	show_WinOrLose(winner);
	if(winner == -1){
		tahap++;
		
		clearBoard_medium(arr);
		summary(live, skor);
		option_ifwin(&live, skor);
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		return;
	}
	if((winner == 1) || (winner == 2)){
		
		clearBoard_medium(arr);
		
		if (live > 0){
			summary(live, skor);
			option_ifKalah_Seri(&live, skor);
		} 
		else {
			ifGameOver(live, skor);
		}
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
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

	winner = checkWin_medium(arr);
	if(winner == 0){
		computerMove_medium(arr);
	}
	
	*ronde = tahap;
	*score = skor;
	*nyawa = live;
	
}

int checkWin_hard(char arr[7][7]){
	/* 
	PIC/Author : Salma Syawalan P
	Deskripsi : mengecek apakah sudah ada simbol yang membentuk pola di papan permainan ukuran 7x7
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan P. 
	Deskripsi : mengecek apakah papan permainan berukuran 7x7 sudah terisi penuh atau tidak.
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : untuk mengosongkan seluruh isi kotak pada papan permainan 7x7.
	IS : kotak pada papan 7x7 terisi simbol
	FS : kotak pada papan 7x7 sudah kosong
	*/
	
	int baris, kolom;
	for(baris=0; baris<7; baris++){
		for(kolom=0; kolom<7; kolom++){
			arr[baris][kolom] = ' ';
		}
	}
}


void randomComputer_hard(char arr[7][7]){
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : menentukan langkah yang akan diambil komputer di papan permainan berukuran 7x7
	IS : salah satu kotak pada papan 7x7 kosong
	FS : salah satu kotak pada papan 7x7 sudah terisi oleh simbol O
	*/
	
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
	/* 
	PIC/Author : Rifatia Yumna S.
	Deskripsi : mengacak kotak pada papan 7x7 yang akan diisi simbol milik player saat player menginput lebih dari 10 detik
	IS : suatu kotak belum terisi oleh simbol
	FS : suatu kota terisi oleh simbol X secara acak
	*/
	
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
	/* 
	PIC/Author : Salma Syawalan P.
	Deskripsi : menampilkan tampilan game pada level hard
	IS : program tidak menampilkan apapun
	FS : program menampilkan tampilan game level hard
	*/
	
	time_t start, end;
	float waktu;
	int baris, kolom, terisi;
	terisi=0;
	int winner;
	int tahap = *ronde;
	int skor = *score;
	int live = *nyawa;
	system("cls");
	
	winner = checkWin_hard(arr);
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
	
	
	show_WinOrLose(winner);
	if(winner == -1){
		tahap++;
		clearBoard_hard(arr);
		if (tahap <= 3){
			summary(live, skor);
			option_ifwin(&live, skor);
		}
		else{
			ifVictory(live, skor);
		}
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
		return;
	}
	if((winner==1) || (winner==2)){
		clearBoard_hard(arr);
		if (live > 0){
			summary(live, skor);
			option_ifKalah_Seri(&live, skor);
		} 
		else{
			ifGameOver(live, skor);
		}
		*ronde = tahap;
		*score = skor;
		*nyawa = live;
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
	
	winner = checkWin_hard(arr);
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
	
	int on = 1;
	int baris, kolom;
	
	home();
	
	while(on == 1){
		int nyawa=3;
		int score=10;
		int ronde=1;
	
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
}
