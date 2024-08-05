dp = Digital Pin

HARDWARE:
 LCD screen, or shield (preferred)
 keypad 4X4
 Arduino, or Arduino MEGA (preferred)
 jumper wires to taste
 
SETUP:
 for MEGA
		  TOP
  [(R1)(R2)(R3)(R4)(C1)(C2)(C3)(C4)]  // facing the keypad connector top being the keys held upwards
    
  R1 --> dp22   C1 --> dp23
  R2 --> dp24   C2 --> dp25
  R3 --> dp26   C3 --> dp26
  R4 --> dp28   C4 --> dp29

  dp30 --> sucsefful output  // connect this to what you want to control apon a correct entry eg, LED, solinoid, fan, relay, ect...

  dp31 --> GND  // this is how the lockout mechanisim works, when the 5th incorrect code is entered this conned dp31 DIRECTLY to GND, this shutsdown most arduino functions   	        	           untill reset button is manually pressed reseting the pin state
