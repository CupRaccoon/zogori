
# module: tokrules.py

from ply.lex import TOKEN


states = (
    ('multistring1', 'exclusive'),
    ('multistring2', 'exclusive'),
)
# else 는 분기문 숫자로 고려 X
reserved = {
    'if': 'IF',
    'elif':'ELIF',
    'else':'ELSE',
    'then': 'THEN',
    'while': 'WHILE',
    'for': 'FOR',
    'del':"DEL",
    'is':"IS",
    'not':"NOT",
    'in':"IN",
    'global':"GLOBAL",

}

# list of token names. this is always required
tokens = [
    'ID',
    'NUMBER',
    'LPAREN',
    'RPAREN',
    'COMMENT',
    'STRING',
    'FUNCTION',
    'MULTISTRING',
    'OPERATOR',
    'BRACE',
    'BRACKET'
] + list(reserved.values())

t_LPAREN = r'\('
t_RPAREN = r'\)'
t_BRACKET = r'[\[\]]'
t_BRACE = r'[\{\}]'
t_OPERATOR = r'[+/&%^~\-|*=<->!,]+'
t_COMMENT = r'\#.*?\n'
t_STRING = r'\".*?\"|\'.*?\''
id = r'[a-zA-Z_][a-zA-Z_0-9]*'
function =r'' + id + '\((.|\n)*?\)'

@TOKEN(function)
def t_FUNCTION(t):
    t.type = reserved.get(t.value, 'FUNCTION')
    return t

# a regular expression rule with some action code
def t_ID(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    t.type = reserved.get(t.value, 'ID')  # Check for reserved words
    return t

# this rule matches numbers and convers the string into a python integer.
def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t

# Error handling rule
def t_error(t):
    print('illegal character "%s"' %t.value[0])
    t.lexer.skip(1)

def t_multistring1(t):
    r'\'{3}'
    t.lexer.code_start  = t.lexer.lexpos-3
    t.lexer.begin('multistring1')

def t_multistring1_end(t):
    r'.*?\'{3}\n?'
    t.value = t.lexer.lexdata[t.lexer.code_start:t.lexer.lexpos]
    t.type = "MULTISTRING"
    t.lexer.begin('INITIAL')
    return t

def t_multistring1_str(t):
    r'.*?\n'


def t_multistring2(t):
    r'\"{3}'
    t.lexer.code_start = t.lexer.lexpos-3
    # Record the starting position
    t.lexer.begin('multistring2')


def t_multistring2_end(t):
    r'.*?\"{3}\n?'
    t.value = t.lexer.lexdata[t.lexer.code_start:t.lexer.lexpos]
    t.type = "MULTISTRING"
    t.lexer.begin('INITIAL')
    return t

def t_multistring2_str(t):
    r'.*?\n'

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

t_ignore = ' \t:.'
#t_ignore_COMMENT = r'\#.*'

