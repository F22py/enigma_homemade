# enigma_homemade
Implementation of Enigma machine with possibility of using your own alphabet, rotors and reflectors. This machine does not implement the double stepping feature of the historical machine. This is the university project for subject Algorithms and Data structures.

Enigma
Your task is to implement a variant of an Enigma machine which encrypts messages in a given alphabet A={a0, a1,...,an} of length n. An element of alphabet ai is called a letter and can consist of at most 128 of characters from the following set:

abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?
Rotors Wx={wx, 0, wx, 1,...,wx, n}and reflectors Ry={ry, 0, ry, 1,...,ry, n} simulate mechanical parts that can be used by an operator. A given permutation of the alphabet specifies wiring of the described rotor. This internal wiring does not change. When aligned with the alphabet passing through it is a simple substitution cipher ai->ri, however rotors can move if certain conditions are fulfilled (more information below).

Typing a letter into the input encrypts it by passing it through the rotors into reflector and back through the rotors in the inverse sequence, as seen here

Each rotor can shift counterclockwise by at most one step during each encoding. The position of a rotor is denoted by a letter - first letter of the alphabet corresponds to the position aligned with the alphabet as stated in the input, second after one rotation, etc. This encoding of the rotors position is used when specifing it's initial position and turnover letters. Refer to the scetion "Turnover notch positions" of the link and this section

The first rotor moves before every encoding. Therefore if the initial position of a single rotor is denoted by the last letter of the alphabet (see example I) the first letter is encoded according to substitutions as stated in the rotor's definition. If a rotor's position changes to one of its turnover letters, then the next rotor is advanced (e.g. if ai is a turnover letter of the first rotor then if the first rotor's position moves from ai-1 to ai, then the second rotor also moves). Note that this variant does not implement the double stepping feature of the historical machine.

If a letter or character (including whitespace characters) is not in the alphabet skip it. Character $ signals the end of a message to encode and is never a part of a letter.

Input can be tought as divided into two parts: definitions of pieces of the machine and p instructions how to encode a given message using some of those parts. Before encoding a message the machine is assembled from k out of m rotors and a single reflector (out of l) and the rotors are set to some initial positions. Refer to the input section for details.

Input:
Defintions of parts of the machine:
n- number of letters of the alphabet 
letters of the alphabet separated by whitespace characters 
m - number of rotors, followed by their definitions W0,...,Wm-1 
definition of rotor Wi - permutation of the alphabet 
number of letters which cause turnover, followed by these letters 
l - number of reflectors 
definitions of reflectors R0,...,Rl-1 - permutation of the alphabet 

A set of p tasks to perform:
p number of texts 
k - number of rotors in the machine 
k pairs - index of a rotor and its initial position (number of rotations prior to encoding) 
index of a reflector 
a sequence of letters (may contain whitespace characters) to encrypt, ending with the $ character
Output:
encrypted sequence of letters (without the $ character)
Exmple I input:
4
aa bb cd ee 
4
bb ee aa cd 
0  
aa cd bb ee
1 cd
aa bb cd ee
0
aa bb ee cd
0
1
bb aa ee cd

4
1 0 ee 0
aaaaaaaabbbbbbbbcdcdcdcdeeeeeeee$
2 1 ee 0 aa 0
aaaaaaaabbbbbbbbcdcdcdcdeeeeeeee$
1 2 ee 0
aaaaaaaabbbbbbbbcdcdcdcdeeeeeeee$
1 3 ee 0
aaaaaaaabbbbbbbbcdcdcdcdeeeeeeee$
Example I output:
cdbbcdbbeeaaeeaaaaeeaaeebbcdbbcd
bbeecdbbeeaaaacdeebbaaeebbcdcdaa
bbbbbbbbaaaaaaaaeeeeeeeecdcdcdcd
bbcdbbcdaaeeaaeeeeaaeeaacdbbcdbb
Exmple II input (based on Enigma I):
26
a b c d e f g h i j k l m n o p q r s t u v w x y z   
3 
e k m f l g d q v z n t o w y h x u s p a i b r c j  
1 r  
a j d k s i r u x b l h w t m c q g z n p y f v o e 
1 e 
b d f h j l c p r t x v z n y e i w g a k m u s q o  
1 v  
2  
e j m z a l y x v b w f c r q u o n t s p i k h g d  
i m e t c g f r a y s q b z x w l h k d v u p o j n  
2
3 0 a 1 b 2 c 0 
clmotgedogykqsibtfnhjzlkkimmfdfx$  
4 0 a 1 a 2 a 0 a 1 
wkabdehrafcrkihqejhxxmosvfmkduhweberdrtvibewdkidfbvhvpwnphdartpwdtwlfqwunjrmzjlvphuqboevumuuztnuiuzcudwmwxxcncabcuofx$  
Example II output:
whitekilledbyappledippedinpoison
eankwxdodtbymouwhfipvqvjllpqshudjdyjhgwpntkplqggsyxknzttgfwghenllfkbxeyyjkhnwqbolfbcosiwjqaadvarmovzscyeimmyiqcawclss


THIS TEXT AND TASK WAS BRING FROM GDANSK UNIVERSITY OF TECHNOLOGY SITE FOR STUDENTS WORKS. PROGRAM WAS MADE AND IMPLEMENTED BY ME
