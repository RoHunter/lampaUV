#include <xc.h> // include processor files - each processor file is guarded.  

void init_hd44780();
void write_char_hd44780(char chr);
void write_string_hd44780(char *string, unsigned rand);
void row_sel_hd44780(unsigned row);




