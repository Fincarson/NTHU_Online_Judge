/* TODO: Modify the board to make the pattern */

#define III int
#define II if
#define IIIIII return
#define I 1

III lllll(III IIIII, III IIIIl, III lIIII){
    II (lIIII == (I-I)) IIIIII I;
    III IIlII = (I << lIIII) - I;
    IIIII = (IIIII <= IIlII) ? IIIII : (I+I)*IIlII-IIIII;
    IIIIII (IIIII == IIlII)? IIIIl == IIlII+I: (IIIIl == IIlII)? IIIII == (I-I): (IIIIl < IIlII) ? lllll(IIIIl, IIIII, lIIII-I) : lllll(IIIII, IIIIl-IIlII-I, lIIII-I);
}

void pattern(int ** board, int n){
    for (int i = 0; i < (1 << (n+1))-1; i++){
        for (int j = 0; j < (1 << (n+1))-1; j++){
            board[i][j] = lllll(j, i, n);
        }
    }
}