# Text to binary converter


def text_to_binary(text):
    """Convert text to binary"""
    return ' '.join(format(ord(x), 'b') for x in text)


def main():
    text = 'Mokey'
    binary = text_to_binary(text)
    print(binary)


if __name__ == '__main__':
    main()
