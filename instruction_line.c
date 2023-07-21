#include "instruction_line.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

struct InstructionLine {
    unsigned short data;
    unsigned long binary_line_index;
};
i_line create_iline() {
    i_line il = malloc(sizeof(struct InstructionLine));
    il->data = 0;
    return il;
}

unsigned short i_line_get_data(i_line line) {
    return line->data;
}

void set_target_address_type(i_line i, address_type a_type) {
    i->data = (i->data & 0xFE3) | (a_type << 2);
}
void set_source_address_type(i_line i, address_type a_type) {
    i->data = (i->data & 0x1FF) | (a_type << 9);
}

void set_encoding(i_line i, encoding e) {
    i->data = (i->data & 0xFFC) | e;
}
void set_register_source_operand(i_line i, register_name r) {
    i->data = (i->data & 0x7F) |  (r << 7);
}
void set_register_target_operand(i_line i, register_name r) {
    i->data = (i->data & 0xF83) |  (r << 2);
}
void set_label_address(i_line i, unsigned short label_address) {
    i->data = (i->data & 0x003) | (label_address << 2);
}

void set_data_full(i_line i, short data) {
    if(data < 0) {
        i->data = (1 << 12) + data;
    } else {
        i->data = (i->data & 0x000) | (data);
    }
}

void set_char(i_line i, char data) {
    i->data = (i->data & 0x003) | data;
}

void set_data(i_line i, short data) {
    if(data < 0) {
        i->data = (1 << 12) + (data << 2);
    } else {
        i->data = (i->data & 0x000) | (data << 2);
    }
}

void set_operation(i_line i, operation op) {
    i->data = (i->data & 0xF1E) | (op << 5);
}

void print_i_line(i_line i) {
    if(i == NULL) {
        printf("NULL\n");
        return;
    }
    printBinary(i->data);
}

void print_iline_in_base64(i_line i) {
    /*convertToBase64(i->data);*/
}