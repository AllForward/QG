<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>服务跳转页面 !</title>
</head>
<body>
<h3>判断用户输入的信息是否和数据库中的信息匹配</h3>
<%
 	String name = request.getParameter("username");//获取name的参数值
	String password = request.getParameter("password");//获取password的参数值
%>
<%
 	Class.forName("com.mysql.jdbc.Driver");//加载mysql驱动
 	Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/用户登录界面", "root","guopei111666");//localhost是本机地址，3306是端口号，最后是用户名和密码
 	Statement stmt = conn.createStatement();//实例化Statement对象
 	String queryresult = "SELECT * from p_user where username='"+name+"' and password='"+password+"'";
 	ResultSet rs = stmt.executeQuery(queryresult);//执行数据库查询操作并获取结果集
 	boolean flag = false;//初始化flag
 	if(rs.next()){//判断结果
 		flag = true;
 		session.setAttribute("username", name);//将name的内容赋值给username
 	}
 	else{
 		flag = false;
 	}
%>
<%
 	if(flag){											
%>
<jsp:forward page="login_success.jsp"></jsp:forward>//跳转登陆成功页面
<%
 	}else{
%>
<jsp:forward page="login_failed.jsp"></jsp:forward>//跳转登陆失败页面
<%
 	}
//关闭上面的几个对象
%>

</body>
</html>
