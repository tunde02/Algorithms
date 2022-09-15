# word = input()

# cnt = len(word)
# for i in range(len(word)):
#     if word[i] == '-':
#         cnt -= 1
#     elif word[i] == 'j':
#         if i - 1 >= 0 and (word[i - 1] == 'l' or word[i - 1] == 'n'):
#             cnt -= 1
#     elif word[i] == '=':
#         cnt -= 1
#         if i - 2 >= 0 and word[i - 2] == 'd' and word[i - 1] == 'z':
#             cnt -= 1

# print(cnt)


croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
word = input()

checks=  0
for c in croatia:
    checks += word.count(c)

print(len(word) - checks)