unsigned int Gia_tri_moi;
void setup()
{
    TCCR1A = 0;
    TCCR1B = 0;
    // RESET lại 2 thanh ghi
    DDRB |= (1 << PB1);
    // Đầu ra PB1 là OUTPUT ( pin 9)
 
    TCCR1A |= (1 << WGM11);
    TCCR1B |= (1 << WGM12) | (1 << WGM13);
    // chọn Fast PWM, chế độ chọn TOP_value tự do  ICR1
    TCCR1A |= (1 << COM1A1);
    // So sánh thường( none-inverting)
 
    TCCR1B |= (1 << CS11);
    // P_clock=16mhz/8=2mhz
    // mỗi P_clock bằng 1/2mhz= 0.5 us
    OCR1A = 1060;
    Gia_tri_moi = OCR1A;
    // Value=1060 , tương đương xung có độ rộng 1060*0.5us=530us (0.53ms)
    // Value=4820, tương đương xung có độ rộng 4820*0.5us=2410us (2,41ms)
    ICR1 = 40000;
    // xung răng cưa tràn sau 40000 P_clock, tương đương (20ms)
}
 
void set(unsigned int x)
{
    if (Gia_tri_moi != x) {
        OCR1A = x;
        Gia_tri_moi = OCR1A;
    }
    else {
        return; // thoát ngay
    }
    // x : 1060 - 4820
    //Độ rộng: 0.53ms - 2.41 ms
}
 
void loop()
{
    set(1060); // 0 độ9666
    delay(1000);
    set(4820); // 180 độ
    delay(1000);
}
