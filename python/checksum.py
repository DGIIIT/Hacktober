# checksum 
# author : Om Rawal
# 15/09/2020 19:31


def BinaryToDecimal(binary):  
         
    binary1 = binary  
    decimal, i, n = 0, 0, 0
    while(binary != 0):  
        dec = binary % 10
        decimal = decimal + dec * pow(2, i)  
        binary = binary//10
        i += 1
    return (decimal)     

def binaryToDec(n): 
    return int(n,2) 

print('Welcome to CheckSum')
message=input('Enter the message to send.: ')
print('Message entered is ',message)
print('Generating Dataword ...')
dataword=[] #length 7
for i in range(len(message)):
    if(message[i]!=' '):
        res = ''.join(format(k, 'b') for k in bytearray(message[i], encoding ='utf-8'))
        dataword.append(res)
    else:
        res = ''.join(format(k, 'b') for k in bytearray(message[i], encoding ='utf-8'))
        res='0'+res
        dataword.append(res)
print('calculating checksum......')
csum='0000000'
for i in dataword:
    csum= bin(int(csum,2) + int(i,2))[2:]
dataword.append(csum)

print('sending dataword......')
print(''.join(dataword))
flag=int(input('1. To induce error\n2. To have no error'))
if(flag==1):
    index=int(input('Enter Index: '))
    ak=''.join(dataword)
    k=list(ak)
    # print('k',k)
    # print('ak',ak)
    if(k[index]=='0'):
        k[index]='1'
    else:
        k[index]='0'
    a=[]
    i=0
    while(i<len(k)):
        kk=''.join(k[i:i+7])
        a.append(kk)
        i+=7
    dataword=a

print('receiving dataword......')
print(''.join(dataword))
print('checking error....')
csum='0000000'
for i in range(len(dataword)-1):
    csum= bin(int(csum,2) + int(dataword[i],2))[2:]
if(csum==dataword[len(dataword)-1]):
    print('No Error')
    print('Decoding message...')
    bin_data=''.join(dataword[:len(dataword)-1])
    print("The binary value is:", bin_data) 
    decoded_message =' '
    for i in range(0, len(bin_data), 7): 

        temp_data = int(bin_data[i:i + 7]) 

        decimal_data = BinaryToDecimal(temp_data) 
        decoded_message = decoded_message + chr(decimal_data)  

    print("The Decoded message is: ",  
        decoded_message) 

else:
    print('Error!!!\n Requesing Retransmission.....')
    # diff= bin(abs(int(csum,2) - int(dataword[i],2)))[2:]
    # print(binaryToDec(diff))
