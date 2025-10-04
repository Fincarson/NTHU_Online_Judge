def pun(sentences: list, queries: list)->None:
    #Write your code here


(line, query) = map(int, input().split())
sentences = []
queries = []
for i in range(line):
    sentences.append(input())
for i in range(query):
    queries.append(tuple(map(int, input().split())))
pun(sentences, queries)