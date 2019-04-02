<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
<script type="text/javascript">// <![CDATA[ 
String.prototype.trim = function () { 
	return this.replace(/^\s+/, '').replace(/\s+$/, ''); 
}; 
	function calc() { 
	var expression = document.getElementById("txtExpression").value; 
	try { 
		document.getElementById("txtResult").innerText ='计算结果为:'+ calcBasic(calcComplex(expression)); 
	} 
	catch(e) { 
		document.getElementById("txtResult").innerText = e.message; 
	} 
} 
	function calcComplex(complexExpression) { 
	var arr = new Array(); 
	var left = 0; 
	var right = 0; 
	for (var i = 0; i < complexExpression.length; i++) { 
	if (complexExpression.charAt(i) == '(') { 
		arr.push(i); 
		left++; 
	} 
	if (complexExpression.charAt(i) == ')') { 
		arr.push(i); 
		right++; 
		}
	if ((complexExpression.charAt(i) >= 'a'&&complexExpression.charAt(i) <= 'z')||
			(complexExpression.charAt(i) >= 'A'&&complexExpression.charAt(i) <= 'Z'))
		throw new Error('存在非法符号！');
	}
	if((complexExpression.charAt(i-1) < '0'||complexExpression.charAt(i-1) > '9')&&complexExpression.charAt(i-1) != ')'){
			throw new Error('存在非法符号！');
	}
	if (left != right) { 
		throw new Error('括号不匹配！');
	} 
	var brackets = complexExpression.replace(/[^\(|^\)]/g, ''); 
	
	for (i = 0; i < brackets.length; i++) { 
		if (brackets.charAt(i) == "(" && brackets.charAt(i + 1) == ")") { 
			var simpleExpression = complexExpression.substr(arr[i] + 1, arr[i + 1] - arr[i] - 1); 
		if (calcBasic(simpleExpression)<0) { 
			complexExpression = complexExpression.substr(0, arr[i]) + '[' + Math.abs(calcBasic(simpleExpression)) + '' + complexExpression.substr(arr[i + 1] + 1); 
		} 
		else { 
		complexExpression = complexExpression.substr(0, arr[i]) + '' + calcBasic(simpleExpression) + '' + complexExpression.substr(arr[i + 1] + 1); 
			} 
		complexExpression=calcComplex(complexExpression); 
		break; 
		} 
	} 
	return complexExpression; 
} 
	function calcBasic(baseExpression) { 
		if (baseExpression.charAt(0)=='-') { 
			baseExpression = '[' + baseExpression.substr(1); 
		} 
		var constants = baseExpression.trim().replace(/[\*|\/|\+|\-]/g, ' ').split(/\s+/g); 
		for (var index in constants) { 
		//只留下符号 
			baseExpression = baseExpression.replace(/\s+/g, '').replace(constants[index], ''); 

		//将提取的常量字符串转化为数字 
			var item; 
			if (constants[index].trim().charAt(0)=='[') { 
				item = parseFloat(constants[index].trim().replace('[','-')); 
			} 
			else { 
				item = parseFloat(constants[index].trim()); 
			} 	
	
			if (isNaN(item)) { 
				throw new Error('存在非法符号！'); 
			} 
			else { 
				constants[index] = item; 
			} 
		} 
			if (constants.length != baseExpression.length + 1) { 
				throw new Error('表达式有误！'); 
			}
			
	for (var i = 0; i < baseExpression.length; i++) { 
		switch (baseExpression.charAt(i)) { 
			case '*': 
				constants.splice(i, 2, constants[i] * constants[i + 1]); 
				baseExpression = baseExpression.replace('*', ''); 
				i -= 1; 
				break; 
			case '/': 
				if (constants[i + 1] == 0) { 
				throw new Error('除数不能为0！'); 
				} 
				constants.splice(i, 2, constants[i] / constants[i + 1]); 
				baseExpression = baseExpression.replace('/', ''); 
				i -= 1; 
				break; 
			default: break; 
		} 
	} 
	for (var j = 0; j < baseExpression.length; j++) { 
		switch (baseExpression.charAt(j)) { 
			case '+': 
				constants.splice(j, 2, constants[j] + constants[j + 1]); 
				baseExpression = baseExpression.replace('+', ''); 
				j -= 1; 
				break; 
			case '-': 
				constants.splice(j, 2, constants[j] - constants[j + 1]); 
				baseExpression = baseExpression.replace('-', ''); 
				j -= 1; 
				break; 
			default: break; 
		} 
	} 

	return constants[0]; 
} 
// ]]></script> 
</p> 
<div style="text-align: center;"><textarea id="txtExpression" style="width: 90%; height: 200px; overflow-y: visible;"></textarea>
 
<div style="width: 90%; margin: 4px auto; text-align: left;"><input id="btnSubit" type="button" onclick="calc()" value="计算" /> <span id="txtResult"></span></div> 
