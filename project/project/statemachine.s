;Comments;

sound: word 0;

init_state:
    call switch_init;
    call led_init;

state_advance:
    cmp #0, sw4_state_down;
    jz s4out;
    cmp #0, sound;
    jz s4out;
    call buzzer_init;
    call buzzer_set_period;

s4out:
    cmp #0, sw2_state_down;
    jz s2out;
    cmp #0, sound;
    jz s2out;
    call buzzer_init;
    call buzzer_set_period;

s2out:
    cmp #0, sw2_state_down;
    jz s2out;
    cmp #0, sound;
    jz s2out;
    call buzzer_init;
    call buzzer_set_period;

s2out:
    cmp #0, sw2_state_down;
    jz s2out;
    cmp #0, sound;
    jz s2out;
    call songOne;

s3out:
    cmp #0, sw3_state_down;
    jz s1out;
    call led_update;
    cmp #0, sound;
    jz else;
    mov #0, sound;
    call buzzer_set_period;
else:
    mov #1, sound