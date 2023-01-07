# List concatenation and reversing

```c
typedef struct ListNode* NODE;

NODE mergeTwoLists(NODE list1, NODE list2){
  NODE p = list1;
  if (list1 == NULL && list2 != NULL)
    return list2;
  else if (list2 == NULL && list1 != NULL)
    return list1;
  else if (list1 == NULL && list2 == NULL)
    return NULL;
  else{
    while (p->next != NULL){
      p = p->next;
    }
    p->next = list2;
  }

  int temp;
  NODE lol = list1;

  while (lol->next != NULL){
    NODE wow = lol->next;
    while (wow != NULL){
      if ((lol->val) > (wow->val)){
        temp = lol->val;
        lol->val = wow->val;
        wow->val = temp;
      }
      wow = wow->next;
    }
    lol = lol->next;
  }
  
  return list1;
}
```
