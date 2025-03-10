greet_list = ['hello', 'good luck', 'morning', 'good time']
stored_list = []


def show_messages(original_list, sent_list):
    for i in range(len(original_list)):
        message = original_list.pop()
        sent_list.append(message)
    print(original_list)
    print(sent_list)


show_messages(greet_list[:], stored_list)
print(greet_list)
print(stored_list)