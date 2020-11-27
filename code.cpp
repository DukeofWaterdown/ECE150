//Thanks Andy! Have a wonderful weekend :)

  if (this->p_head == nullptr || this->p_head->get_next() == nullptr) {
    return;
  }
  else {

    //create new list to store sorted elements
      Transaction *p_head_sorted {nullptr};

      //go through the original list and move each node one by one
      while (this->p_head != nullptr) {

        //remove node from original list
        Transaction *p_trans_move{p_head};
        this->p_head = this->p_head->get_next();
        p_trans_move->set_next(nullptr);

        //insert at the top of the list
        if (p_head_sorted == nullptr) {
          p_head_sorted = p_trans_move;
        }
        else if (*p_trans_move  *p_head_sorted) {
          p_trans_move->set_next(p_head_sorted);
          p_head_sorted = p_trans_move;
        }
        //insert somewhere in the middle or end of list
        else {
          Transaction *p_prev {nullptr};
          Transaction *p_traverse {p_head_sorted};

          while (p_traverse != nullptr) {
            if (!(*p_traverse < *p_trans_move)) {
              p_prev->set_next(p_trans_move);
              p_trans_move->set_next(p_traverse);
              break;
            }
            p_prev = p_traverse;
            // p_traverse = p_traverse->get_next();
            p_prev->set_next(p_trans_move);
          }


          //insert at end of list
          if (p_traverse == nullptr) {
            p_traverse = p_trans_move;
          }
        }

        p_head = p_head_sorted;
      }
}

        //Original: {6->{} } || p_head
        //Sorted: {1->2->3->5->6}
