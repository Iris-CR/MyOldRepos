import cs50


def main():
    text = cs50.get_string("Text: ")
    letters = 0
    words = 0
    sent = 0
    for i in range(0, len(text)):
        if text[i].isalpha():
            letters += 1
        elif text[i] == ' ':
            words += 1
        elif text[i] == '.' or text[i] == '!' or text[i] == '?':
            sent += 1
    words += 1
    cli = 0.0588 * average_by_100(letters, words) - 0.296 * average_by_100(sent, words) - 15.8
    grade = round(cli)
    if cli < 1:
        print("Before Grade 1")
    elif (cli > 16):
        print("Grade 16+\n")
    else:
        print("Grade", grade)


def average_by_100(a, b):
    return 100 * a / b


main()
