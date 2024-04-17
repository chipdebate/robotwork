 void Init()
  {    
    case_sensitive_ = false;
    current = nullptr; end = nullptr; last_found = nullptr;//yes
  }

  bool FindNext_CaseSensitive()
  {
    while (current < end)
    {
      uint8_t i = shift[static_cast<unsigned>(*current)];  //compare last byte first
      if (!i)                   //last byte matches if i == 0
      {
        char* j = current - needle_len_less1;
        while (i < needle_len_less1 && needle_[i] == *(j + i)) ++i;
        if (i == needle_len_less1)
        {
          ++current;
          last_found = j;
          return true;
        }
        else
          current += jump_;
      }
      else
        current += i;
    }
    return false;
  }
//good work
