# Dziele na pary 
def divide_to_chunks(message,chunk=2):
    return [message[i:i+chunk] for i in range(0,len(message),chunk)]

# Konwertuje cala wiadomosc do ciagu bajtow
def convert_to_bytes(message):
    binary_message = ''
    for char in message:
        binary = format(ord(char), '08b')
        binary_message += binary
    return binary_message

# Umieszcam bit kontrolny w stringu
def insert_control_bit(message, char, position):
    return message[:position]+ char + message[position:]

# Okreslam miejsca wstawienia bitow kontrolnych
# umieszczam placeholdery '0'
def determine_control_bit_place(message):
    bit_pow = 0
    while (2 ** bit_pow) < len(message):
        bit_position = (2 ** bit_pow)
        message = insert_control_bit(message, '0', bit_position-1 )    
        bit_pow += 1
    return message

def clear_control_bit(message):
    bit_pow = 0
    while (2 ** bit_pow) < len(message):
        bit_position = (2 ** bit_pow)
        message = set_value(message,'0',bit_position-1)
        bit_pow += 1
    return message    

#obliczam sume bitow kontrolowanych przez bit kontrolny
def sum_control_bit(message,chunk):
    if (len(message) == 0 ):
        return 0
    
    move = 2*chunk
    control_sum = sum_control_bit(message[move:],chunk)

    for i in range(0, min(chunk, len(message))):
        control_sum += int(message[i])

    return control_sum

# Podstawiam nowa wartosc znaku w stringu
def set_value(message,value,position):
    return message[:position]+ value + message[position+1:]

# Obliczam wartosc bitow kontrolnych
def compute_control_bit(message):
    bit_pow = 0        
    while (2 ** bit_pow) < len(message):
        bit_position = (2 ** bit_pow)
        control_bit_value = (sum_control_bit(message[bit_position-1:],bit_position)) % 2
        message = set_value(message,str(control_bit_value),bit_position-1)
        bit_pow += 1
    return message

def test_control_sum(message):
    chunks = divide_to_chunks(message,21)
    for chunk in chunks:
        clear_test_value = clear_control_bit(chunk)
        test_value = compute_control_bit(clear_test_value)
        differences = [i+1 for i in range(len(test_value)) if test_value[i] != chunk[i] ]
        if len(differences) > 0:
            print(f"Blad w ciagu: {test_value} na pozycji {sum(differences)}")
        
#########################################

message = input("Wprowadź wiadomość: ")
print("Wiadomość:", message)

pairs = divide_to_chunks(message)
print(f"Pary znakow: {pairs}")
byte_messages = []
for idx, pair in enumerate(pairs):
    byte_message = convert_to_bytes(pair)
    message_with_placeholders = determine_control_bit_place(byte_message)        
    byte_messages.append(compute_control_bit(message_with_placeholders))

prepared_message = "".join(byte_messages)
print(f"Gotowa wiadomosc: {prepared_message}")

#######
# Celowe wprowadzenie bledu (1 na pare znakow) do ciagu znakow
false_message = input("Wprowadz zmodyfikowany (bledny) ciag:")
test_control_sum(false_message)
