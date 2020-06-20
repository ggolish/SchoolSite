// oct-30-2017-a
int main() {
  // initialize variables
  int count = 0;
  
  for(ptr = head; ptr != NULL; ptr = ptr->next) {
    // do something with data
    if (ptr->data >= 100) count++;
  }

  // some conclusions?
  printf("Total count: %i\n", count);
}

// oct-30-2017-b
int main() {
  // initialize variables
  int pos=0, neg=0, zero=0;
  
  for(ptr = head; ptr != NULL; ptr = ptr->next) {
    // do something with data
    if (ptr->data > 0) pos++;
    else if (ptr->data < 0) neg++;
    else zero++;
  }

  // some conclusions?
  printf("Total counts: %i, %i, %i\n", neg, zero, pos);
}

// nov-13-2017-a
int main() {

  // last node node considered, one behind ptr
  node_t *last = NULL; 
  
  for(ptr = head; ptr != NULL; ptr = ptr->next) {
    if (last != NULL && ptr->data >= last->data) break;

    // print, keep going
    printf("%d\n", ptr->data);

    // save ptr as "last", just before ptr=ptr->next happens
    last = ptr;
  }
}

// nov-13-2017-b - change >= to <=

// nov-27-2017-a
int main() {
  int numItems = 0;
  int totalLength = 0;
  
  for(ptr = head; ptr != NULL; ptr = ptr->next) {
    if (ptr->str != NULL) 
      totalLength += strlen(ptr->str);
    numItems++;
  }

  double avg = ((double) totalLength) / numItems; 
  printf("%lf\n", avg);
}

// nov-27-2017-b
int main() {
  int numItems = 0;
  int capitalCount = 0;
  
  for(ptr = head; ptr != NULL; ptr = ptr->next) {
    if (ptr->str != NULL) {
      char ch = ptr->str[0];
      if (isupper(ch)) // (ch >= 'A' && ch <= 'Z')
	capitalCount;
    }
    
    numItems++;
  }

  double frac = ((double) capitalCount) / numItems; 
  printf("%lf\n", frac);
}


// dec-06-2017-a
int main() {

  int number = 0;
  for(ptr = head; ptr != NULL; ptr = ptr->next) {
    if (number % 2 == 0)
      printf("%d\n", ptr->data);
    
    number++;
  }

  /*
  ptr = head;
  while (ptr != NULL) {
    printf("%d\n", ptr->data);

    ptr = ptr->next;
    if (ptr != NULL)
      ptr = ptr->next;
  }
   */
}

// dec-06-2017-b, want increasing order (non-decreasing)
int main() {

  node_t *last = NULL;
  int okay = 1;
  
  for(ptr = head; ptr != NULL; ptr = ptr->next) {
    if (last != NULL && ptr->data < last->data) {
      okay = 0;
      break;
    }

    // keep going, looks okay so far

    // save ptr as "last", just before ptr=ptr->next happens
    last = ptr;
  }
  
  if (okay) printf("sorted\n");
  else printf("not sorted\n");
}