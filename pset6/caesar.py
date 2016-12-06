import cs50
import sys

# check for argument's validation
if len(sys.argv)!=2:
    print("Usage ./saesar key")
    exit(1)
# key must be > 0
elif (int(sys.argv[1])<0):
    print("Key must be possitive")
else:
    # crypt the entire text
    print("plaintext: ", end = '')
    text = cs50.get_string()
    crypt = []
    for i in range(len(text)):
        if (text[i].isupper()):
            crypt.append( chr((((ord(text[i]) - ord('A')) + int(sys.argv[1])) % 26) + ord('A')) )
        else:
            crypt.append( chr((((ord(text[i]) - ord('a')) + int(sys.argv[1])) % 26) + ord('a')) )
    # output encrypted text
    print("ciphertext: ", end = '')
    print("".join(crypt))