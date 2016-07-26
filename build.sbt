name := "JCLCudaAPI"
version := "1.0"
organization := "ca.uwaterloo.jclcudaapi"
scalaVersion := "2.11.7"
javacOptions ++= Seq("-source", "1.8", "-target", "1.8", "-Xlint")
javaOptions += "-Xmx2g -Djava.library.path=lib"
crossPaths := false
autoScalaLibrary := false
initialize := {
  val _ = initialize.value
  if (sys.props("java.specification.version") != "1.8")
    sys.error("Java 8 is required for this project.")
}
