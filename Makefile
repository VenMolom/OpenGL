.PHONY: clean All

All:
	@echo "----------Building project:[ OpenGLProject - Debug ]----------"
	@"$(MAKE)" -f  "OpenGLProject.mk"
clean:
	@echo "----------Cleaning project:[ OpenGLProject - Debug ]----------"
	@"$(MAKE)" -f  "OpenGLProject.mk" clean
