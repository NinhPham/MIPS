# MIPS
Maximum inner product search (MIPS) algorithms

The C++ source code for MIPS (using CodeBlock) written by Ninh Pham (ninh.pham@auckland.ac.nz)

To use Eigen Lib,
- In Project/Buid Options/Search Directories, add C:\_Data\Libraries\eigen-eigen-5a0156e40feb (where Eigen Lib locates)

Parameters: 
<PARAM_DATA_N> <PARAM_QUERY_Q> <PARAM_DATA_D> <PARAM_MIPS_TOP_K> <filename_of_data> <filename_of_query> <method> <param_of_method>

- <PARAM_DATA_N>: number of rows (instances) of Data
- <PARAM_QUERY_Q>: number of rows (queries) of Queries
- <PARAM_DATA_D>: number of dimensions
- <filename_of_data>: filename of Data with matrix format N x D (N is number of objects)
- <filename_of_query>: filename of Query with matrix format Q x D (Q is number of queries)

Method (see InputParser.cpp file for more details):
- "BF": bruteforce search (no parameters)
- "1CEOs_Search" D = 1024 (number of random projections), b = 100 (post-processing number of inner products)
- "2CEOs_Search" D = 1024, b = 100 
- "simpleLSH_Table" l = 24 (number of hash functions), L = 512 (number of hash tables), b = 100
- "rangeLSH_Table" l = 16, L = 512, p = 4 (number of partitions), b = 100
- "dWedge" S = 10000 (number of samples), b = 100
- "greedy" b = 100
- "Gauss_RP" l = 128 (number of random projections), b = 100
- "simpleLSH_Code" l = 128 (number of random projections), b = 100
- "rangeLSH_Code" l = 128, p = 4 (number of partitions), b = 100
- "coCEOs_Est" D = 1024 (number of random projections), s0 = 5 (number of concomitants for max or min), b = 100
- "coCEOs_TA" D = 1024, s0 = 5, b = 100
- "coCEOs_Search" 1024, s0 = 5, S = 10000 (number of samples), b = 100

Sample Scripts:

Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "BF"

Output.exe 1000000 1000 960 10 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "1CEOs_Search" 1024 100
Output.exe 1000000 1000 960 10 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "2CEOs_Search" 1024 100
Output.exe 1000000 1000 960 10 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "simpleLSH_Table" 24 512 100
Output.exe 1000000 1000 960 10 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "rangeLSH_Table" 16 512 4 100

Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "dWedge" 10000 100
Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "greedy" 100
Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "Gauss_RP" 128 100
Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "simHash_Code" 128 100
Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "simpleLSH_Code" 128 100
Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "rangeLSH_Code" 128 4 100

Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "sCEOs_Est" 1024 5 100
Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "sCEOs_TA" 1024 5 100
Output.exe 1000000 1000 960 100 "C:\_Data\Dataset\_MIPS\Gist\_X_1000000_960.txt" "C:\_Data\Dataset\_MIPS\Gist\_Q_1000_960.txt" "coCEOs_Search" 1024 5 10000 100
