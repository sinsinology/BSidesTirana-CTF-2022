
# Developer

Idea from Welcome-CTF

this challenge is easy, a js file containing the flag, divided to chunks, manual work is involved to retireve the flag

![BSides-Tirana](01.png)
![BSides-Tirana](02.png)


# Neo

Triggering Change Flag
![BSides-Tirana](03.png)

Says there is something missing
![BSides-Tirana](03-B.png)


Monnitor File-System Calls using procmon revelas the app is trying to open a handle to a file at temp called `matrix.key` but it does not exist
![BSides-Tirana](03-C.png)

Manual creation of this file results in below result (Win)

![BSides-Tirana](04.png)






# Encryptor


Encrypor.exe & flag.txt

![BSides-Tirana](05.png)

flag.txt has been changed

![BSides-Tirana](06.png)

Encryptor.exe accept a file as input and transforms the file
![BSides-Tirana](07.png)

Transformation mechanism is simple, each character XORed with the same character + 10
![BSides-Tirana](08.png)




