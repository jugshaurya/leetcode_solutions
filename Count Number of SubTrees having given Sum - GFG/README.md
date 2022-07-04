# Count Number of SubTrees having given Sum
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a binary tree&nbsp;and an integer <strong>X</strong>. Your task is to complete the function <strong>countSubtreesWithSumX()</strong> that returns the count of the number of subtress having total node’s data sum equal to the&nbsp;value <strong>X</strong>.</span><br>
<span style="font-size:18px"><strong>Example:</strong> For the tree given below: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></p>

<p><span style="font-size:18px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 5<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp; \<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -10&nbsp;&nbsp;&nbsp;&nbsp; 3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp; \ &nbsp;&nbsp; /&nbsp; \<br>
&nbsp; &nbsp; &nbsp; 9 &nbsp;&nbsp;&nbsp; 8&nbsp; -4 7</span></p>

<p><span style="font-size:18px">Subtree with sum 7:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -10<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8</span></p>

<p><span style="font-size:18px">and one node 7.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>       5
&nbsp;   /    \
&nbsp; -10     3
&nbsp;/   \   /  \
&nbsp;9   8 -4    7
X = 7
<strong>Output: </strong>2<strong>
Explanation: </strong>Subtrees with sum 7 are
[9, 8, -10] and [7] (refer the example
in the problem description).</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>    1
&nbsp; /  \
&nbsp;2    3
X = 5
<strong>Output: </strong>0<strong>
Explanation: </strong>No subtree has sum equal
to 5.</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your&nbsp;task is to complete the function&nbsp;<strong>countSubtreesWithSumX</strong>() which takes the root node and an integer X as inputs and returns the number of subtrees of the given Binary Tree having sum exactly equal to X.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N).<br>
<strong>Expected Auxiliary Space: </strong>O(Height of the Tree).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= N &lt;= 10</span><sup>3</sup><br>
<span style="font-size:18px">-10</span><sup>3</sup><span style="font-size:18px"> &lt;= Node Value &lt;= 10</span><sup>3</sup><br>
&nbsp;</p>

<p><span style="font-size:14px"><strong>Note</strong>:The <strong>Input/Ouput</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</span></p>
 <p></p>
            </div>