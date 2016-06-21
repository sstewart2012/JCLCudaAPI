package ca.uwaterloo.JCLCudaAPI;

import java.util.List;

public interface Program {

	/** The possible build statuses of the program. */
	static enum BuildStatus {
		buildSuccess, buildError, buildInvalid
	}
	
	/** Compiles the program for the specified device and options. */
	BuildStatus build(Device d, List<String> options);
	
	/** Returns any warnings or errors reported by the compiler. */
	String getBuildInfo(Device d);
	
	/** Returns an intermediate representation of the program. */
	String getIR();
	
}
