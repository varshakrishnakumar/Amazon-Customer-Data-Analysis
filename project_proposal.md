## Examination and Comprehensive Visualization of Consumer Behavior of Amazon Customers

Aiushe Mishra, Lisa Pachikara, Riya Gyanmote, Varsha Krishnakumar
 
### Background of Study

As one of the leading online global markets, Amazon employs a multitude of marketing techniques and motifs with the objective of elevating a culmination of product and customer engagement. Based on this engagement, Amazon is equipped with the propensity to profile consumers on their product preferences. With the examination of the consumer’s purchase dataset, including time and content of purchase, Amazon is able to formulate the personal recommendation tactic[1]. This employed method of marketing is commonly a constituent of Referral Marketing, where a product is merchandised through the business’ existing consumer circle. The implication of this employed method of marketing allows for the analysis of consumer behavior. This theme is an intended and compelling point of examination due to its potential of predicting consumer purchasing trends in the future and present market of Amazon. Therefore, the considered objective with this project is to **understand and visualize consumer interactions with the objective of pointing to consumer trends that can be extrapolated on a larger scale in the form of a strongly connected components and graph coloring.** With this visualization, the marketing strategy of purchase trend analysis and action is made more efficient, due to the existence of visible cluttering on the purchase of products across Amazon. 

### Objective

Produce comprehensive deliverables of a strongly connected graph and a colored graph with the intention of detecting recurring cluttering structures in the dataset for determining purchasing trends between products frequently co-purchased together.

### Dataset Acquisition and Processing

The data set we are using we found on the Stanford Network Database <sup>2</sup> which was resultant from a study done in Carnegie Mellon called the Dynamics of Viral Marketing<sup>3</sup>, which is where we acquired the Amazon product co-purchasing network. We were able to get the data with the help of Professor Evans and from the CS225 resources page. After downloading the data set we plan to import it into Visual Studio Code, which will make it easier for our code and methods to access and process the data. In order to handle errors or missing entries in our data set, we plan to create extensive test cases for our traversal code.

### Graph Algorithms
The two graph algorithms that our team plans on implementing are a strongly connected components graph and a graph coloring algorithm. Our strongly connected graph will be created with all of our dataset, helping us categorize the nodes (or items). The graph coloring will help us visually organize our clusters into colors so we better understand the relationship between clusters. Organizing the data in this way allows us to visually represent the data in a form where we are easily able to see the different trends across consumer data. We plan to use a depth-first search traversal in order to attain our target big O. Our target big O for our strongly connected graph is the edges added to the vertices, O(E + V). For our force-directed graph, our target big O is O(n<sup>3</sup>).

### Project Timeline

Week 1 (4/5 - 4/9):
* Complete Team Contract
* Complete Final Project Proposal
* Data acquisition and submission to group Git account

Week 2 (4/12 - 4/16): 
* Exposition and understanding of the implementation of the Strongly Connected Graph
* Initiate work on data traversal using a Depth First Search

Week 3 (4/19 -  4/23):
* Continue implementation of data traversal
* Composition of simple test cases
* Mid-Project Check In with mentor
* Begin implementation of Strongly Connected Components Graph 

Week 4 (4/26 - 4/30): 
* Initiate implementation of graph coloring
* Composition of more test cases for data traversal and Strongly Connected Components Graph
* Creation and completion of google slides/ powerpoint for presentation deliverable
* Assignment of presentation sections to individual team members

Week 5 (5/3 - 5/7):
* Begin process of filming the presentation
* Completion of graph coloring
* Composition of possible edge test cases, engagement in debugging

Week 6 (5/10- 5/14):
* Final formatting of graphs and other deliverables.
* Commit any final minor changes to Github
* Condense and produce final video presentation

 
### Citations

[1]: Srivastava, Abhishek. “Motif Analysis in the Amazon Product Co-Purchasing Network.” https://arxiv.org/pdf/1012.4050.pdf.

[2]: Stanford University. “Amazon product co-purchasing network, March 02 2003.” http://snap.stanford.edu/data/amazon0302.html.

[3]: J. Leskovec, L. Adamic and B. Adamic. The Dynamics of Viral Marketing. ACM Transactions on the Web (ACM TWEB), 1(1), 2007.
