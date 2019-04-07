<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>注册页面 !</title>
</head>
<body>
<script>
	function checkName(){//检查用户名是否输入正确
		var name = document.getElementById("username").value;
		var spanNode = document.getElementById("namespan");  
		if(name == null){
			spanNode.innerHTML = "用户名不能为空!".fontcolor("red");
			document.getElementById("username").focus();
			return false;  
		}
		else{
			 spanNode.innerHTML = "".fontcolor("green");
			 return true; 
		}
	}
	function checkPassword(){
		var password = document.getElementById("password").value;  
	    var spanNode = document.getElementById("passwordspan");
	    if(password == null){
	    	 spanNode.innerHTML = "密码不能为空".fontcolor("red");
	    	 document.getElementById("passwordclass").focus();
	    	 return false;  
	    }
	    else{
	    	spanNode.innerHTML = "".fontcolor("green");
			 return true; 
	    }
	}
	function checkSame(){
		var password = document.getElementById("password").value;
		var password2 = document.getElementById("newword").value;
		var spanNode = document.getElementById("newword");  
		if(password != newword){
			spanNode.innerHTML = "两次密码输入不同！".fontcolor("red");
			document.getElementById("newword").focus();
			return false;
		}
		else{
			spanNode.innerHTML = "".fontcolor("green");
			return true; 
		}
	}
	function checkAll(){ 
		var name = checkName();         
		var password = checkPassword();       
		var same = checkSame();      
		if(name&&password&&same){         
			return true;         
		}
		else{
			return false;
		}
	} 
</script>
<body>
	<center>
		<font face="楷体" size="4" color="black">注册界面</font>
		<form action="checkregister.jsp" method="get"
			onsubmit="return checkAll()">
			<table width="300" height="180" border="5" bordercolor="#A0A0A0">
				<tr>
					<th>用户名：</th>
					<td><input type="text" name="username" value="输入16个字符以内"
						maxlength="16"onblur="checkName()"
						onfocus="if(this.value == '输入16个字符以内') this.value =''"></td>
						
				</tr>
				<tr>
					<th>输入密码：</th>
					<td><input type="text" name="password" value="输入20个字符以内"
						maxlength="20"onblur="checkPassword()"
						onfocus="if(this.value == '输入20个字符以内') this.value =''"></td>
					
				</tr>
				<tr>
					<td colspan="2" align="center">
						<input type="submit"value="提  交"> 
						<input type="reset" value="重  置"></td>
				</tr>
			</table>
		</form>
	</center>
	<font color="red"><a href="login.jsp">点击我</a>回到主页！</font>
</body>
</body>
</html>