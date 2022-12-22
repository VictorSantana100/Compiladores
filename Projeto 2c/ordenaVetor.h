void bublesort(PONT* x, int n){
  int i, j;
  PONT* buff;
  int flag = 1;

  for (i = 0; i < n - 1 && flag; i++){
      flag = 0;
      for (j = 0; j < n - i - 1; j++)
	    if (x[j]->id > x[j + 1]->id){
	    flag = 1;
	    buff = x[j];
	    x[j] = x[j + 1];
	    x[j + 1] = buff;
	  }
    }
}