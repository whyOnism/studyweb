alert("Hello World!!!");
//document.write("<h1>Hello World</h1>");
console.log("这是后台输出用来观察输出值");
/* 输出 在正常编写的页面的上面 输出不可控 无法控制元素顺序 */
/* 之所以使用Chrome 因为他有后台的代码调试 使用方便 使用console.log()进行后台输出进行代码调试 */
var num = 10;     //定义整型变量
var nnum;  //定义未知变量
console.log(typeof num);//判断什么类型的变量
console.log(typeof nnum);
/* if(nnum == undefined){ //现在nnum变量还没设置
	alert("该变量现在还没有设置内容");	
} */

if(nnum){
	alert("该变量现在还没有设置内容");	
}
else{
	alert("该变量有内容");	
}
/* 在JS中可以直接在if语句之中使用变量直接判断 如果此变量属于undefined表示false 否则表示true */
/* 在JS中使用""或''都表示字符串 和JAVA操作类似 */

var str = 'Hello World very nice';   //定义变量
var result = str.split(" ");
for(var x = 0 ; x < result.length ; x ++){
	document.write("<h1>" + (result[x]) + "</h1>");
}

/* 在Java里字符串的比较方式有两种: ==或equals()  但在JS中只有'=='*/
var stra = 'hello';
var strb = 'hello';
alert(stra == strb);
var strc = 'helloworld';
alert(strc.indexOf("l") != -1);
/* 在Java里所使用的各种string类操作方法都可以在JS里有更简单的操作方法 */
/* 范例:使用JS输出乘法口诀(使用表格控制) */
document.write("<table border='1'>")
for(var x = 1 ; x <= 9 ; x ++){
	document.write("<tr>"); 
	for(var y = 1 ; y <= x ; y ++){
		document.write("<td>" + x + "*" + y + "=" + (x * y) + "</td>");
	}
	for(var y = 1 ; y <= 9 - x ; y ++){
		document.write("<td>&nbsp;</td>");
	}
	document.write("</tr>");
}
document.write("</table>");

/* 创建数组 */
var arr = new Array();
arr[0] = "Hello";
arr[1] = 100;
arr[2] = true;//动态初始化数组
var arr1 = new Array("Hello","World","LPL");//静态初始化数组
for(var x = 0 ; x < arr.length ; x ++){
	document.write("<h2>"+arr[x]+"-->"+(typeof arr[x])+"</h2>")
}
for(var x = 0 ; x < arr1.length ; x ++){
	document.write("<h2>"+arr1[x]+"-->"+(typeof arr1[x])+"</h2>")
}

function add(x,y){
	switch(add.arguments.length){
		case 0 :
			return 0 ;
		case 1 :
			return x ;
		case 2 :
			return x + y ;
		default :
			return "不可能的操作" ;
	}
}
alert(add(20,5000,2929));//要语法要求严格

function Book(title,price){   //定义了一个类
	this.title = title;
	this.price = price;
}
//prototype属于对原生的操作扩展
Book.prototype.getInfo = function(){
	//return "这是一本书！";
	return "title = " + this.title + "price = " + this.price ;
}
//book表示接受了Book类返回的函数
var book = new Book("Java",79.8);  //构造函数
alert(book.getInfo());





