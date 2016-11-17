# Ball and Beam with Arduino
Example usage of EFLL library in arduino.
## EFLL Lib
http://www.zerokol.com/2012/09/arduinofuzzy-fuzzy-library-for-arduino.html

## Modeling
![alt tag](http://ctms.engin.umich.edu/CTMS/Content/BallBeam/Simulink/Modeling/figures/bb2.png)
http://ctms.engin.umich.edu/CTMS/Content/BallBeam/Simulink/Modeling/figures/bb2.png, University of Michigan

## Fuzzy Sets Graphs
![alt tag](https://raw.githubusercontent.com/hugomarquez/ball_and_beam/master/graphs/fuzzy_sets.png)

## Rules
| Rules | Position | Set Point | Theta |
|-------|----------|-----------|-------|
| 1     | NM       | NM        | ZO    |
| 2     | NM       | NS        | NS    |
| 3     | NM       | ZO        | NS    |
| 4     | NM       | PS        | NS    |
| 5     | NM       | PM        | NM    |
| 6     | NS       | NM        | ZO    |
| 7     | NS       | NS        | ZO    |
| 8     | NS       | ZO        | NS    |
| 9     | NS       | PS        | NS    |
| 10    | NS       | NM        | NM    |
| 11    | ZO       | NM        | PS    |
| 12    | ZO       | NS        | PS    |
| 13    | ZO       | ZO        | ZO    |
| 14    | ZO       | PS        | ZO    |
| 15    | ZO       | PM        | NS    |
| 16    | PS       | NM        | PM    |
| 17    | PS       | NS        | PS    |
| 18    | PS       | ZO        | ZO    |
| 19    | PS       | PS        | ZO    |
| 20    | PS       | PM        | ZO    |
| 21    | PM       | NM        | PM    |
| 22    | PM       | NS        | PM    |
| 23    | PM       | ZO        | PS    |
| 24    | PM       | PS        | ZO    |
| 25    | PM       | PM        | ZO    |
