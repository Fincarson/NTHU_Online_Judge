def pun(sentences: list, queries: list)->None:
    sentences_2D = [s.split() for s in sentences]

    for I, J in queries:
        output = []
        for i in range(I, len(sentences_2D)):
            j = J if J < len(sentences_2D[i]) else len(sentences_2D[i]) - 1
            output.append(sentences_2D[i][j])
        print(" ".join(output))
        

(line, query) = map(int, input().split())
sentences = []
queries = []
for i in range(line):
    sentences.append(input())
for i in range(query):
    queries.append(tuple(map(int, input().split())))
pun(sentences, queries)